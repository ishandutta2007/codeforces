#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10,INF=1e9;
int T,n,m,a[MAXN],l[MAXN],r[MAXN];
int lim[MAXN],pre[MAXN],cur;
set<int>occ[MAXN];
int qry_pre(set<int>& s,int val){
    if(s.empty())return -1;
    auto it=s.lower_bound(val);if(it==s.begin())return -1;
    it--;int ret=*it;if(ret<val)return ret;return -1;
}
int qry_nxt(set<int>& s,int val){
    if(s.empty())return -1;
    auto it=s.upper_bound(val);if(it==s.end())return -1;
    int ret=*it;if(ret>val)return ret;return -1;
}
void add_pos(int pos){
    int pv=qry_pre(occ[a[pos]],pos),nv=qry_nxt(occ[a[pos]],pos);
    pre[pos]=pv;
    if(pre[pos]>=lim[pos])cur++;
    if(nv!=-1){
        if(pre[nv]>=lim[nv])cur--;
        pre[nv]=pos;
        if(pre[nv]>=lim[nv])cur++;
    }
    occ[a[pos]].insert(pos);
}
void del_pos(int pos){
    int pv=qry_pre(occ[a[pos]],pos),nv=qry_nxt(occ[a[pos]],pos);
    if(pre[pos]>=lim[pos])cur--;
    if(nv!=-1){
        if(pre[nv]>=lim[nv])cur--;
        pre[nv]=pv;
        if(pre[nv]>=lim[nv])cur++;
    }
    occ[a[pos]].erase(pos);
}
namespace D{
    int b[MAXN],tot;
    vector<int>add[MAXN],del[MAXN];
    void process(){
        tot=0;rep(i,1,n)b[++tot]=a[i];
        sort(b+1,b+1+tot);tot=unique(b+1,b+1+tot)-b-1;
        rep(i,1,n)a[i]=lower_bound(b+1,b+1+tot,a[i])-b;

        rep(i,1,n)add[i].clear(),del[i].clear();
        rep(i,1,m)add[l[i]].push_back(l[i]),del[r[i]].push_back(l[i]);
        multiset<int>S;
        rep(i,1,n){
            lim[i]=INF;
            for(auto u:add[i])S.insert(u);
            if(S.size())lim[i]=*S.begin();
            for(auto u:del[i])S.erase(S.find(u));
        }

        cur=0;
        rep(i,1,tot)occ[i].clear();
        rep(i,1,n)occ[a[i]].insert(i);
        rep(i,1,n)pre[i]=qry_pre(occ[a[i]],i);
        rep(i,1,n)if(pre[i]>=lim[i])cur++;
        if(!cur){cout<<0<<'\n';return;}
        int ans=n;
        int L=1,R=1;
        while(L<=n){
            if(R<L)R=L;
            while(R<=n && cur){
                del_pos(R);
                R++;    
            }
            if(!cur)ans=min(ans,R-L);
            add_pos(L);L++;
        }
        cout<<ans<<'\n';
    }
};
void solve(){
    cin>>n>>m;
    rep(i,1,n)cin>>a[i];
    rep(i,1,m)cin>>l[i]>>r[i];
    D::process();
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}