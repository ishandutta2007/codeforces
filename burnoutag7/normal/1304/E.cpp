#include<bits/stdc++.h>
using namespace std;

struct NODE{
    NODE *nxt=NULL;
    int val=0;
};

struct LIST{
    NODE *head=new NODE,*tail=head;
    void push(int val){
        tail->val=val;
        tail->nxt=new NODE;
        tail=tail->nxt;
    }
};

int n,m,s;
LIST g[100005];
int d[100005];
int p[100005][20];

void dfs(int x,int pr,int dep){
    p[x][0]=pr;
    d[x]=dep;
    for(NODE *it=g[x].head;it!=g[x].tail;it=it->nxt){
        if(it->val!=pr){
            dfs(it->val,x,dep+1);
        }
    }
}

void init(){
    dfs(s,-1,0);
    for(int j=0;j<19;j++){
        for(int i=1;i<=n;i++){
            if(p[i][j]==-1)p[i][j+1]=-1;
            else p[i][j+1]=p[p[i][j]][j];
        }
    }
}

int lca(int u,int v){
    if(d[u]<d[v])swap(u,v);
    for(int k=19;k>=0;k--){
        if(p[u][k]!=-1&&d[p[u][k]]>=d[v])u=p[u][k];
    }
    if(u==v)return u;
    for(int k=19;k>=0;k--){
        if(p[u][k]!=p[v][k]){
            u=p[u][k];
            v=p[v][k];
        }
    }
    return p[u][0];
}

int dist(int u,int v){
    int anc=lca(u,v);
    return d[u]-d[anc]+d[v]-d[anc];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;s=1;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push(b);
        g[b].push(a);
    }
    init();
    cin>>m;
    while(m--){
        int x,y,a,b,k;
        cin>>x>>y>>a>>b>>k;
        int path1=dist(a,b);//cout<<path1<<' ';
        int path2=dist(a,x)+1+dist(y,b);//cout<<path2<<' ';
        int path3=dist(a,y)+1+dist(x,b);//cout<<path3<<'\n';
        if((path1<=k&&((k-path1)&1)==0)
        ||(path2<=k&&((k-path2)&1)==0)
        ||(path3<=k&&((k-path3)&1)==0)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }

    return 0;
}