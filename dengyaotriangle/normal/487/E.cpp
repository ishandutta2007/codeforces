#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=100005;

int n,m,q;
int pr[maxn];
vector<int> adj[maxn];
int tfa[maxn],dfn[maxn],low[maxn],c1,c2;
vector<int> tdj[maxn<<1];
stack<int> stk;
int tfn[maxn<<1],top[maxn<<1],hvs[maxn<<1],id[maxn<<1],sze[maxn<<1],dep[maxn<<1],val[maxn<<1],fa[maxn<<1],c3;
multiset<int> h[maxn<<1];

void tarjan(int u){
    dfn[u]=low[u]=++c1;
    stk.push(u);
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!dfn[v]){
            tfa[v]=u;
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                ++c2;
                while(1){
                    int w=stk.top();stk.pop();
                    tdj[c2].push_back(w);
                    tdj[w].push_back(c2);
                    if(w==v)break;
                }
                tdj[c2].push_back(u);
                tdj[u].push_back(c2);
            }
        }else if(v!=tfa[u]) low[u]=min(low[u],dfn[v]);
    }
}

void dfs1(int u){
    sze[u]=1;
    int mx=0,mxi=0;
    val[u]=0x3f3f3f3f;
    for(int i=0;i<tdj[u].size();i++){
        int v=tdj[u][i];
        if(!dep[v]){
            dep[v]=dep[u]+1;
            fa[v]=u;
            dfs1(v);
            sze[u]+=sze[v];
            if(sze[v]>mx){
                mx=sze[v];
                mxi=v;
            }
            if(u>n){
                h[u].insert(pr[v]);
                val[u]=min(val[u],pr[v]);
            }
        }
    }
    hvs[u]=mxi;
}
void dfs2(int u){
    tfn[u]=++c3;
    id[c3]=u;
    if(hvs[u]){
        top[hvs[u]]=top[u];
        dfs2(hvs[u]);
    }
    for(int i=0;i<tdj[u].size();i++){
        int v=tdj[u][i];
        if(dep[v]==dep[u]+1&&v!=hvs[u]){
            top[v]=v;
            dfs2(v);
        }
    }
}

struct node{
    int v;
    node* c[2];
};

node pool[maxn<<3];
int ps;

inline node* nwnode(){
    node* nw=pool+ps++;
    nw->v=0x3f3f3f3f;nw->c[0]=nw->c[1]=NULL;
    return nw;
}

inline void pu(node* rt){
    if(rt){
        if(rt->c[0]){
            rt->v=min(rt->c[0]->v,rt->c[1]->v);
        }
    }
}

node* bt(int l,int r){
    node* nw=nwnode();
    if(l!=r){
        nw->c[0]=bt(l,(l+r)>>1);
        nw->c[1]=bt(((l+r)>>1)+1,r);
        pu(nw);
    }else{
        nw->v=val[id[l]];
    }
    return nw;
}

void chg(node* rt,int i,int v,int cl,int cr){
    int cm=(cl+cr)>>1;
    if(cl==cr){
        rt->v=v;
    }else if(i<=cm)chg(rt->c[0],i,v,cl,cm);
    else chg(rt->c[1],i,v,cm+1,cr);
    pu(rt);
}

int qry(node* rt,int l,int r,int cl,int cr){
    int cm=(cl+cr)>>1;
    if(cl==l&&cr==r){
        return rt->v;
    }else if(r<=cm)return qry(rt->c[0],l,r,cl,cm);
    else if(l>cm)return qry(rt->c[1],l,r,cm+1,cr);
    else return min(qry(rt->c[0],l,cm,cl,cm),qry(rt->c[1],cm+1,r,cm+1,cr));
}

node* rt;
inline int qrl(int u,int v){
    int ans=0x3f3f3f3f;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);/*
        cerr<<u<<','<<v<<endl;
        cerr<<dep[u]<<','<<dep[v]<<endl;
        cerr<<top[u]<<','<<top[v]<<endl;*/
        ans=min(ans,qry(rt,tfn[top[u]],tfn[u],1,c3));
        u=fa[top[u]];
    }
    if(dep[u]>dep[v])swap(u,v);
    ans=min(ans,qry(rt,tfn[u],tfn[v],1,c3));
    if(u>n&&fa[u]){
        ans=min(ans,pr[fa[u]]);
    }else ans=min(ans,pr[u]);
    return ans;
}

inline void chv(int u,int val){
    int od=pr[u];
    pr[u]=val;
    int v=fa[u];
    if(!v)return;
    int lst=(*h[v].begin());
    h[v].erase(h[v].find(od));
    h[v].insert(val);
    int cr=(*h[v].begin());
    if(lst!=cr)chg(rt,tfn[v],cr,1,c3);
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)cin>>pr[i];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    c2=n;
    tarjan(1);
    dep[1]=1;
    dfs1(1);
    top[1]=1;
    dfs2(1);
    rt=bt(1,c3);
    while(q--){
        char op;
        cin>>op;
        if(op=='C'){
            int a,w;
            cin>>a>>w;
            chv(a,w);
        }else{
            int u,v;
            cin>>u>>v;
            cout<<qrl(u,v)<<'\n';
        }
    }
    return 0;
}