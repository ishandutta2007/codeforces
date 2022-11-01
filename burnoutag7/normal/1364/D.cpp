#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> g[100005];
int dep[100005];
bool u[100005];
int fa[100005][18];

void dfs4lca(int x,int p,int cd){
    u[x]=1;
    fa[x][0]=p;
    dep[x]=cd;
    for(int &y:g[x])if(!u[y]){
        dfs4lca(y,x,cd+1);
    }
}

void init4lca(){
    dfs4lca(1,-1,0);
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

void dfs(int x,int p,int d,vector<int> &res0,vector<int> &res1){
    if(d)res1.emplace_back(x);
    else res0.emplace_back(x);
    for(int &y:g[x])if(y!=p){
        dfs(y,x,d^1,res0,res1);
    }
}

void solvetree(){
    vector<int> res,res0,res1;
    dfs(1,-1,0,res0,res1);
    if(res0.size()>res1.size()){
        res=res0;
    }else{
        res=res1;
    }
    cout<<1<<endl;
    for(int i=0;i<(k+1)/2;i++)cout<<res[i]<<' ';
}

vector<int> getring(int x,int y){
    vector<int> a,b;
    int anc=lca(x,y);
    while(x!=anc){
        a.emplace_back(x);
        x=fa[x][0];
    }
    a.emplace_back(anc);
    while(y!=anc){
        b.emplace_back(y);
        y=fa[y][0];
    }
    reverse(b.begin(),b.end());
    for(int &c:b)a.emplace_back(c);
    return a;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(m==n-1){
        solvetree();
        return 0;
    }
    init4lca();
    int len=1e9,ax=-1,ay=-1;
    for(int x=1;x<=n;x++){
        for(int &y:g[x]){
            if(fa[x][0]!=y&&fa[y][0]!=x){
                int anc=lca(x,y);
                int clen=dep[x]-dep[anc]+dep[y]-dep[anc]+1;
                if(clen<len){
                    len=clen;
                    ax=x;
                    ay=y;
                }
            }
        }
    }
    vector<int> v=getring(ax,ay);
    if(len<=k){
        cout<<2<<endl<<v.size()<<endl;
        for(int i=0;i<v.size();i++)cout<<v[i]<<' ';
    }else{
        cout<<1<<endl;
        for(int i=0,c=0;c<(k+1)/2;i+=2,c++)cout<<v[i]<<' ';
    }

    return 0;
}