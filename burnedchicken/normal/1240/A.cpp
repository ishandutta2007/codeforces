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
const int MOD=Mod2;
 
inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}
 
const int maxn=200005;
//i_am_noob
int q,n,x,a,y,b,p[maxn],k,l,r,mid;

bool solve(int z){
	int tmp=a*b/__gcd(a,b);
	int tmp1=z/tmp;
	int tmp2=z/a-tmp1,tmp3=z/b-tmp1;
	int tmp4=0;
	rep(tmp1) tmp4+=p[i]/100*(x+y);
	if(x>y){
		rep(tmp2) tmp4+=p[tmp1+i]/100*x;
		rep(tmp3) tmp4+=p[tmp1+tmp2+i]/100*y;
	}
	else{
		rep(tmp3) tmp4+=p[tmp1+i]/100*y;
		rep(tmp2) tmp4+=p[tmp1+tmp3+i]/100*x;
	}
	return tmp4>=k;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> q;
	while(q--){
		cin >> n;
		rep(n) cin >> p[i];
		sort(p,p+n);
		reverse(p,p+n);
		cin >> x >> a >> y >> b >> k;
		if(!solve(n)){
			print1(-1);
			continue;
		}
		l=1,r=n;
		while(l!=r){
			mid=l+r>>1;
			if(solve(mid)) r=mid;
			else l=mid+1;
		}
		print1(l);
	}
	return 0;
}