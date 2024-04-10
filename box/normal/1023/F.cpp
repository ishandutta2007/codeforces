// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int mxtag[500005<<2];
void restri(int idx,int l,int r,int L,int R,int val){
    if(L<=l&&r<=R){
        mxtag[idx]=min(mxtag[idx],val);
        return;
    }
    if(R<=l||r<=L)return;
    restri(idx*2,l,(l+r)/2,L,R,val);
    restri(idx*2+1,(l+r)/2,r,L,R,val);
}
int res[500005];
void geres(int idx,int l,int r,int cur){
    cur=min(cur,mxtag[idx]);
    if(r-l==1){
        res[l]=cur;
        return;
    }
    geres(idx*2,l,(l+r)/2,cur);
    geres(idx*2+1,(l+r)/2,r,cur);
}

vector<int> elist[500005];
int subsz[500005],hvch[500005];
int fa[500005];
int dep[500005];

void dfs1(int u,int f){
    dep[u]=dep[f]+1;
    fa[u]=f;subsz[u]=1;
    for(int v:elist[u]){
        if(v==f)continue;
        dfs1(v,u);
        subsz[u]+=subsz[v];
        if(subsz[hvch[u]]<subsz[v])hvch[u]=v;
    }
}

int id[500005], revid[500005], clo;
int hp[500005];

void dfs2(int u,int f,int f2){
    hp[u]=f2;
    id[u]=clo++;
    revid[id[u]]=u;
    if(hvch[u]){
        dfs2(hvch[u],u,f2);
        for(int v:elist[u])if(v!=f&&v!=hvch[u])dfs2(v,u,v);
    }
}

int SEGT_N;

void lnkpush(int u,int v,int w){
    //cout<<u<<' '<<v<<endl;
    while(hp[u]!=hp[v]){
        if(dep[hp[u]]<dep[hp[v]])swap(u,v);
        //id[hp[u]] id[u]
        restri(1,0,SEGT_N,id[hp[u]],id[u]+1,w);
        u=fa[hp[u]];
    }
    if(u!=v){
        //cout<<u<<' '<<v<<' '<<id[u]<<' '<<id[v]<<endl;
        int a=min(id[u],id[v]),b=max(id[u],id[v]);
        // do not include a
        assert(a+1!=b+1);
        restri(1,0,SEGT_N,a+1,b+1,w);
    }
}

int bcj[500005];
int ge(int id){
    if(bcj[id])return bcj[id]=ge(bcj[id]);
    else return id;
}

vector<pii>mst[500005];
int tgv[500005];
vector<int>special;
void toTree(int u,int f){
    for(auto x:mst[u])if(x.fi!=f){
        if(x.se==0){
            special.push_back(x.fi);
        }
        tgv[x.fi]=x.se;
        elist[u].pb(x.fi);
        elist[x.fi].pb(u);
        toTree(x.fi,u);
    }
}

bool notInMST[500005];

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,m;cin>>n>>k>>m;
    rep1(i,(n+6)<<2)mxtag[i]=MOD;
    vector<pii>yud(k);
    int ltk=n;
    rep(i,k){
        cin>>yud[i].fi>>yud[i].se;
        if(ge(yud[i].fi)!=ge(yud[i].se)){
            bcj[ge(yud[i].fi)]=ge(yud[i].se);
            ltk--;
            mst[yud[i].fi].push_back({yud[i].se,0});
            mst[yud[i].se].push_back({yud[i].fi,0});
        }
    }
    vector<pair<int,pii>>bed(m);
    rep(i,m)cin>>bed[i].se.fi>>bed[i].se.se>>bed[i].fi;
    rep(i,m){
        int u=bed[i].se.fi,v=bed[i].se.se;
        if(ge(u)!=ge(v)){
            bcj[ge(u)]=ge(v);
            mst[u].push_back({v,bed[i].fi});
            mst[v].push_back({u,bed[i].fi});
            ltk--;
        }else notInMST[i]=1;
    }
    toTree(1,0);
    dfs1(1,0);
    dfs2(1,0,0);
    SEGT_N=n+5;
    rep(i,m){
        if(!notInMST[i])continue;
        lnkpush(bed[i].se.fi,bed[i].se.se,bed[i].fi);
    }
    geres(1,0,SEGT_N,MOD);
    long long ans=0;
    for(int i:special){
        ans+=res[id[i]];
        if(res[id[i]]==MOD){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}