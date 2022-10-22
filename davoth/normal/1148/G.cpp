#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
//#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MOD=1000000007,MD=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
int n,p[10000005],k,cl[N],f[N],a[N],l[N],r[N],m[N],tr,cnt[10000005],mul[500];
vector<int> pr[N],ans,cq,qu[N];
int lb(int x){
    return x&-x;
}
void add(int x){
    int k=pr[x].size();
    for(int i=0; i<k; i++) mul[(1<<i)]=pr[x][i];
    mul[0]=1;
    for(int i=0; i<(1<<k); i++){
        mul[i]=mul[i^lb(i)]*mul[lb(i)];
        cnt[mul[i]]++;
    }
}
int get(int x){
    int k=pr[x].size(),ans=0;
    for(int i=0; i<k; i++) mul[(1<<i)]=pr[x][i];
    mul[0]=1;
    for(int i=0; i<(1<<k); i++){
        mul[i]=mul[i^lb(i)]*mul[lb(i)];
        if(__builtin_popcount(i)%2==0) ans+=cnt[mul[i]];
        else ans-=cnt[mul[i]];
    }
    return ans;
}
int main(){
    fast_io;
    for(int i=2; i<=1e7; i++){
        if(!p[i]){
            p[i]=i;
            for(ll j=1ll*i*i; j<=1e7; j+=i) p[j]=i;
        }
    }
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        int x=a[i];
        while(x>1){
            int y=p[x];
            while(x%y==0) x/=y;
            pr[i].pb(y);
        }
        r[i]=n;
        add(i);
    }
    for(int i=1; i<=n; i++){
        int x=get(i);
        if(!x){
            cl[i]=1;
            cq.pb(i);
        }else if(x>=2) tr=i;
    }
    if(cq.size()>=k){
        for(int i=0; i<k; i++) cout << cq[i] << ' ';
        cout << '\n';
        return 0;
    }
    for(int z=0; z<17; z++){
        for(int i=1; i<=n; i++){
            if(cl[i] || r[i]-l[i]==1) continue;
            m[i]=(l[i]+r[i])>>1;
            qu[m[i]].pb(i);
        }
        memset(cnt,0,sizeof cnt);
        for(int i=1; i<=n; i++){
            if(!cl[i]) add(i);
            for(int j : qu[i]){
                if(get(j)) r[j]=m[j];
                else l[j]=m[j];
            }
            qu[i]={};
        }
    }
    if(!tr){
        ans=cq;
        for(int i=1; i<=n; i++){
            if(!cl[i] && !f[i] && !f[r[i]]){
                f[i]=f[r[i]]=1;
                ans.pb(i);
            }
        }
    }else if(k&1){
        ans.pb(tr);
        f[tr]=1;
        for(int i=1; i<=n; i++) if(__gcd(a[i],a[tr])==1 && ans.size()<3) ans.pb(i),f[i]=1;
    }
    for(int i=1; i<=n; i++){
        if(!cl[i] && !f[i] && !f[r[i]]){
            ans.pb(i);
            ans.pb(r[i]);
            f[i]=f[r[i]]=1;
        }
    }
    for(int i=1; i<=n; i++){
        if(!cl[i] && !f[i]) ans.pb(i);
    }
    for(int i=0; i<k; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}