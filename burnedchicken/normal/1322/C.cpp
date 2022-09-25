#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a)
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;

inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=500005;
//i_am_noob
int t,n,m,a[maxn],b[maxn][5],u,v,cnt[maxn],noob[maxn][5],c[maxn],ans;
vector<int> vec;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool comp(int i, int j){
    rep1(ii,5){
        if(noob[i][ii]<noob[j][ii]) return true;
        if(noob[i][ii]>noob[j][ii]) return false;
    }
    return false;
}

bool is_zero(int i){
    rep1(ii,5) if(noob[i][ii]) return false;
    return true;
}

bool same(int i, int j){
    rep1(ii,5) if(noob[i][ii]!=noob[j][ii]) return false;
    return true;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        rep(n) cin >> a[i];
        memset(cnt,0,8*n);
        rep(n) rep1(j,5) {b[i][j]=rng()%MOD;noob[i][j]=0;}
        rep(m){
            cin >> u >> v;
            u--,v--;
            cnt[v]++;
            rep1(j,5) noob[v][j]=add(noob[v][j],b[u][j]);
        }
        rep(n) c[i]=i;
        sort(c,c+n,comp);
        vec.clear();
        rep(n){
            if(is_zero(c[i])) continue;
            if(i==0) vec.pb(a[c[i]]);
            else if(!same(c[i-1],c[i])) vec.pb(a[c[i]]);
            else vec.back()+=a[c[i]];
        }
        ans=vec.back();
        rep(sz(vec)-1) ans=__gcd(ans,vec[i]);
        print1(ans);
    }
	return 0;
}