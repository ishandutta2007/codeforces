#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=400405;

int n,p,mx,m;
vector<int> adj[maxn<<2];
int l[maxn],r[maxn];
pair<int,int> li[maxn],ri[maxn];
int dfn[maxn<<2],low[maxn<<2],col[maxn<<2],c1,c2;
stack<int> stk;
bool ins[maxn<<2];

void tarjan(int u){
    stk.push(u);
    dfn[u]=low[u]=++c1;
    ins[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(ins[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        c2++;
        while(1){
            int v=stk.top();stk.pop();
            col[v]=c2;
            ins[v]=0;
            if(u==v)break;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>p>>mx>>m;
    int dv1=(p<<1)+3,dv2=dv1+mx+3,dvt=dv2+mx+2;
    for(int i=dv1+1;i<dv1+mx;i++)adj[i].push_back(i+1);
    for(int i=dv2+mx;i>dv2+1;i--)adj[i].push_back(i-1);
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        adj[x<<1].push_back((y<<1)|1);
        adj[y<<1].push_back((x<<1)|1);
    }
    for(int i=1;i<=p;i++){
        cin>>l[i]>>r[i];
        adj[dv1+l[i]].push_back((i<<1));
        adj[dv2+r[i]].push_back((i<<1));
        if(r[i]+1<=mx)adj[(i<<1)|1].push_back(dv1+r[i]+1);
        if(l[i]-1>=1)adj[(i<<1)|1].push_back(dv2+l[i]-1);
    }
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        adj[(x<<1)|1].push_back(y<<1);
        adj[(y<<1)|1].push_back(x<<1);
    }
    for(int i=1;i<=dvt;i++){
        if(!dfn[i])tarjan(i);
    }/*
    for(int i=1;i<=dvt;i++){
        cout<<i<<' '<<col[i]<<':';
        for(int j=0;j<adj[i].size();j++)cout<<adj[i][j]<<',';
        cout<<endl;
    }*/
    for(int i=1;i<=p;i++){
        if(col[i<<1]==col[(i<<1)|1]){
            cout<<-1;
            return 0;
        }
    }
    vector<int> ans;
    for(int i=1;i<=p;i++){
        if(col[i<<1]>col[(i<<1)|1])ans.push_back(i);
    }
    int mil=0;
    for(int i=0;i<ans.size();i++){
        mil=max(mil,l[ans[i]]);
    }
    cout<<ans.size()<<' '<<mil<<endl;
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
    return 0;
}