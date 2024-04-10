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
 
const int maxn=2005;
//i_am_noob
int h,w,n,dp[maxn],fact[200005],invfact[200005];
pii p[maxn];

bool comp(pii p1, pii p2){return p1.first+p1.second<p2.first+p2.second;}
inline int C(int n, int m){return fact[n]*invfact[m]%MOD*invfact[n-m]%MOD;}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	fact[0]=1;
	rep(200004) fact[i+1]=fact[i]*(i+1)%MOD;
	rep(200005) invfact[i]=inverse(fact[i]);
	cin >> h >> w >> n;
	rep(n) cin >> p[i].first >> p[i].second;
	rep(n) p[i].first--,p[i].second--;
	p[n].first=h-1,p[n].second=w-1;
	sort(p,p+n,comp);
	rep(n+1){
		dp[i]=C(p[i].first+p[i].second,p[i].first);
		rep1(j,i) if(p[j].first<=p[i].first&&p[j].second<=p[i].second) dp[i]=sub(dp[i],dp[j]*C(p[i].first+p[i].second-p[j].first-p[j].second,p[i].first-p[j].first)%MOD);
	}
	print1(dp[n]);
	return 0;
}