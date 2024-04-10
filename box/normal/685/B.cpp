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

int n;
vector<int>elist[300005];
struct dd{
    int u,v,d;
} maxl[300005];
int fa[300005];
int tsz[300005];
int mb[300005];
pii obese[300005];
int maxd(int u,int f){
    tsz[u]=1;fa[u]=f;
    for(int v:elist[u])if(v!=f){
        int k=maxd(v,u);
        tsz[u]+=k;
        mb[u]=max(mb[u],k);
        obese[u]=max(obese[u],{k,v});
    }
    return tsz[u];
}
int brutefindcentr(int u,int f,int n){
    for(int v:elist[u])if(v!=f){
        if(tsz[v]*2>n)return brutefindcentr(v,u,n);
    }
    return u;
}
int objp[300005][20];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q;cin>>n>>q;
    iter(i,2,n+1){
        int fa;cin>>fa;
        elist[fa].push_back(i);
        elist[i].push_back(fa);
    }
    maxd(1,0);
    rep1(i,n)objp[i][0]=obese[i].second;
    rep1(i,19)rep1(j,n)objp[j][i]=objp[objp[j][i-1]][i-1];
    rep(i,q){
        int a;cin>>a;
        int th=tsz[a];
        int cur=a,ans=0;
        if(mb[cur]*2<=th)ans=cur;
        else{
            for(int i=19;i>=0;i--){
                int d=objp[cur][i];
                if(d&&(tsz[d]*2>th))cur=d;
            }
            ans=cur;
            // ans=objp[cur][0];
        }
        // int bb=brutefindcentr(a,fa[a],tsz[a]);
        // cerr<<ans<<' '<<bb<<' '<<tsz[ans]<<' '<<mb[ans]<<' '<<tsz[bb]<<' '<<mb[bb]<<endl;
        // cerr<<objp[ans][0]<<' '<<tsz[objp[ans][0]]<<' '<<mb[objp[ans][0]]<<endl;
        // assert(ans==brutefindcentr(a,fa[a],tsz[a]));
        cout<<ans<<'\n';
    }
}