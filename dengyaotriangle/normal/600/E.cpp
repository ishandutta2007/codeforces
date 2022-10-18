#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=100005;

vector<int> adj[maxn];

struct node{
    int l,r;
    node* c[2];
    int mxi;
    long long mxs;
};

node* nwnode(int l,int r){
    node* nw=new node;
    nw->l=l;nw->r=r;nw->c[0]=nw->c[1]=NULL;nw->mxi=0;nw->mxs=((l==r)?l:0);
    return nw;
}

void pu(node* rt){
    if(rt->l!=rt->r){
        if(!rt->c[0]&&!rt->c[1])rt->mxi=0,rt->mxs=0;
        else if(!rt->c[1])rt->mxi=rt->c[0]->mxi,rt->mxs=rt->c[0]->mxs;
        else if(!rt->c[0])rt->mxi=rt->c[1]->mxi,rt->mxs=rt->c[1]->mxs;
        else{
            if(rt->c[0]->mxi>rt->c[1]->mxi)rt->mxi=rt->c[0]->mxi,rt->mxs=rt->c[0]->mxs;
            else if(rt->c[0]->mxi<rt->c[1]->mxi)rt->mxi=rt->c[1]->mxi,rt->mxs=rt->c[1]->mxs;
            else{
                rt->mxi=rt->c[0]->mxi,rt->mxs=rt->c[0]->mxs+rt->c[1]->mxs;
            }
        }
    }
}
void chg(node* rt,int i){
    int cl=rt->l,cr=rt->r,cm=(cl+cr)>>1;
    if(cl==cr){
        rt->mxi++;
        return;
    }else if(i<=cm){
        if(!rt->c[0])rt->c[0]=nwnode(cl,cm);
        chg(rt->c[0],i);
    }else if(i>cm){
        if(!rt->c[1])rt->c[1]=nwnode(cm+1,cr);
        chg(rt->c[1],i);
    }
    pu(rt);
}
node* mrg(node* a,node* b){
    if(!a)return b;
    if(!b)return a;
    if(a->l==a->r){
        a->mxi+=b->mxi;
        return a;
    }
    a->c[0]=mrg(a->c[0],b->c[0]);
    a->c[1]=mrg(a->c[1],b->c[1]);
    pu(a);
    return a;
}

int c[maxn];
long long ans[maxn];
int dep[maxn];
int n;
node* rt[maxn];

void dfs2(node* rt){
    if(!rt)return;
    cout<<rt->l<<','<<rt->r<<':'<<rt->mxi<<','<<rt->mxs<<'\n';
    dfs2(rt->c[0]);
    dfs2(rt->c[1]);
}
void dfs(int u){
    rt[u]=nwnode(1,n);
    chg(rt[u],c[u]);
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!dep[v]){
            dep[v]=dep[u]+1;
            dfs(v);
            rt[u]=mrg(rt[u],rt[v]);
            //cout<<u<<v<<':';
            //dfs2(rt[u]);
            //cout<<endl;
        }
    }
    ans[u]=rt[u]->mxs;
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dep[1]=1;
    dfs(1);
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    return 0;
}