#include<bits/stdc++.h>
using namespace std;

int n,m,q;
vector<int> g[100005];
int dep[100005],fa[100005][17],odd[100005],ufa[100005],ccnt,ic[100005];

int find(int x){
    if(ufa[x]==x)return x;
    return ufa[x]=find(ufa[x]);
}

void dfs(int x,int p,int cd){
    fa[x][0]=p;
    dep[x]=cd;
    ic[x]=ccnt;
    for(int &y:g[x])if(!ic[y]){
        dfs(y,x,cd+1);
        odd[x]|=odd[y]&&find(x)==find(y);
    }else if(dep[x]>dep[y]+1){
        odd[x]|=(dep[x]^dep[y])&1^1;
        for(int i=find(x);dep[i]>dep[y]+1;i=find(i))ufa[i]=fa[i][0];
    }
}

void init(){
    for(int i=1;i<=n;i++)if(!ic[i]){
        ccnt++;
        dfs(i,-1,0);
    }
    for(int j=0;j<16;j++){
        for(int i=1;i<=n;i++){
            if(fa[i][j]==-1)fa[i][j+1]=-1;
            else fa[i][j+1]=fa[fa[i][j]][j];
        }
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int i=16;i>=0;i--){
        if(fa[x][i]!=-1&&dep[fa[x][i]]>=dep[y])x=fa[x][i];
    }
    if(x==y)return x;
    for(int i=16;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}

void push1(int x){
    for(int &y:g[x])if(fa[y][0]==x){
        odd[y]|=odd[x]&&find(x)==find(y);
        push1(y);
    }
}

void push2(int x){
    for(int &y:g[x])if(fa[y][0]==x){
        odd[y]+=odd[x];
        push2(y);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    iota(ufa,ufa+100001,0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    init();
    for(int i=1;i<=n;i++)if(fa[i][0]==-1){
        push1(i);
        push2(i);
        //ONE-TWO PUSH: Hitting an enemy with every pellet in a shot increases melee damage for a short duration.
    }
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        if(ic[u]!=ic[v]){
            cout<<"No\n";
            continue;
        }
        if((dep[u]^dep[v])&1){
            cout<<"Yes\n";
            continue;
        }
        if(odd[u]+odd[v]-2*odd[lca(u,v)]){
            cout<<"Yes\n";
            continue;
        }
        cout<<"No\n";
    }

    return 0;
}