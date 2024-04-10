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
 
const int maxn=100005;
//i_am_noob
int n,l[2][maxn],r[2][maxn],L[2][maxn],R[2][maxn],a[2][maxn],b[2][maxn],seed,hash_a[2][maxn][3],hash_b[2][maxn][3],x[2],y[2];
bool ok;

bool comp1(int x, int y){return l[0][x]>l[0][y];}
bool comp2(int x, int y){return r[0][x]<r[0][y];}
bool comp3(int x, int y){return l[1][x]>l[1][y];}
bool comp4(int x, int y){return r[1][x]<r[1][y];}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(n) cin >> l[0][i] >> r[0][i] >> l[1][i] >> r[1][i];
	rep(n) rep1(j,2) a[j][i]=b[j][i]=i;
	sort(a[0],a[0]+n,comp1);
	sort(a[1],a[1]+n,comp2);
	sort(b[0],b[0]+n,comp3);
	sort(b[1],b[1]+n,comp4);
	rep(n) L[0][i]=l[0][a[0][n-1-i]];
	rep(n) R[0][i]=r[0][a[1][i]];
	rep(n) L[1][i]=l[1][b[0][n-1-i]];
	rep(n) R[1][i]=r[1][b[1][i]];
	rep1(noob,3){
		if(noob==0) seed=2;
		else if(noob==1) seed=3;
		else seed=5;
		rep1(j,2) hash_a[j][0][noob]=hash_b[j][0][noob]=0;
		rep(n) rep1(j,2){
			hash_a[j][i+1][noob]=add(hash_a[j][i][noob],Pow(seed,a[j][i]));
			hash_b[j][i+1][noob]=add(hash_b[j][i][noob],Pow(seed,b[j][i]));
		}
	}
	rep(n){
		x[0]=upper_bound(L[0],L[0]+n,r[0][i])-L[0];
		x[0]=n-x[0];
		x[1]=lower_bound(R[0],R[0]+n,l[0][i])-R[0];
		y[0]=upper_bound(L[1],L[1]+n,r[1][i])-L[1];
		y[0]=n-y[0];
		y[1]=lower_bound(R[1],R[1]+n,l[1][i])-R[1];
		ok=true;
		if(x[0]+x[1]!=y[0]+y[1]){
			print1("NO");
			return 0;
		}
		rep1(noob,3) if(add(hash_a[0][x[0]][noob],hash_a[1][x[1]][noob])!=add(hash_b[0][y[0]][noob],hash_b[1][y[1]][noob])){
			ok=false;
		}
		if(!ok){
			print1("NO");
			return 0;
		}
	}
	print1("YES");
	return 0;
}