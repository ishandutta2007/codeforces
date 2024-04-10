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

struct qry {
    int l, r, s, t, idx;
    const bool operator<(const qry& o) const {
        return l < o.l;
    }
} qs[200005];

bool ans[200005];
int u[200005], v[200005];
int mxp[1005][1005];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    memset(mxp,0x3f,sizeof mxp);
    int n,m,q;cin>>n>>m>>q;
    rep1(i,m)cin>>u[i]>>v[i];
    rep(i,q){
        cin>>qs[i].l>>qs[i].r>>qs[i].s>>qs[i].t;
        qs[i].idx=i;
    }
    sort(qs,qs+q);
    int pos=q-1;
    for(int i=m;i>=1;i--){
        rep1(j,n)mxp[j][j]=i;
        int U=u[i],V=v[i];
        rep1(j,n){
            int a=min(mxp[U][j],mxp[V][j]);
            // mxp[U][j]=mxp[V][j]=mxp[j][U]=mxp[j][V]=a;
            mxp[U][j]=mxp[V][j]=a;
        }
        while(pos!=-1&&qs[pos].l==i){
            auto [l,r,s,t,idx]=qs[pos];
            // assert(mxp[s][t]==mxp[t][s]);
            // ans[idx]=(min(mxp[s][t],mxp[t][s])<=r);
            ans[idx]=(mxp[s][t]<=r);
            pos--;
        }
    }
    rep(i,q)cout<<(ans[i]?"Yes":"No")<<'\n';
}