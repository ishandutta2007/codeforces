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
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
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

const int maxn=400005;
//i_am_noob
int n,fact[maxn],invfact[maxn],sum[maxn/2],sum2[maxn/2],ans=0;
string str;

inline int C(int m, int n){return n<0||n>m?0:fact[m]*invfact[n]%MOD*invfact[m-n]%MOD;}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    fact[0]=1;
    rep2(i,1,maxn) fact[i]=fact[i-1]*i%MOD;
    rep(maxn) invfact[i]=inverse(fact[i]);
    cin >> str;
    n=sz(str);
    sum[0]=0;
    rep(n) sum[i+1]=sum[i]+(str[i]=='(');
    sum2[0]=0;
    rep(n) sum2[i+1]=sum2[i]+(str[n-1-i]==')');
    rep(n) if(str[i]=='(') ans=add(ans,C(sum[i]+sum2[n-1-i],sum2[n-1-i]-1));
    print1(ans);
    return 0;
}