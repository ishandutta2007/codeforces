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
int n,k,dp[maxn][maxn],cost[maxn][10];
string str[maxn],num[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
bool ok;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> k;
	rep(n) cin >> str[i];
	rep(n) rep1(j,10){
		cost[i][j]=0;
		rep1(l,7){
			if(num[j][l]=='0'&&str[i][l]=='1'){
				cost[i][j]=-1;
				break;
			}
			if(num[j][l]=='1'&&str[i][l]=='0') cost[i][j]++;
		}
	}
	rep(maxn) dp[0][i]=-1;
	dp[0][0]=0;
	rep2(i,1,n+1) rep1(j,maxn){
		ok=false;
		rep3(l,9,0){
			if(cost[n-i][l]==-1||cost[n-i][l]>j) continue;
			if(dp[i-1][j-cost[n-i][l]]>=0){
				dp[i][j]=l;
				ok=true;
				break;
			}
		}
		if(!ok) dp[i][j]=-1;
	}
	if(dp[n][k]==-1){
		print1(-1);
		return 0;
	}
	rep3(i,n,1){
		cout << dp[i][k];
		k-=cost[n-i][dp[i][k]];
	}
	cout << '\n';
	return 0;
}