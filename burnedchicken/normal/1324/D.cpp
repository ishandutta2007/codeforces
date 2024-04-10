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
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define debug(a) print2(#a,a)
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
int dgts2(int n){return (n?dgts2(n>>1)+1:0);}
int dgts(int n, int k){return (n?dgts(n/k,k)+1:0);}
inline int v2(int n){return __builtin_ctzll(n);}
 
const int maxn=200005;
//i_am_noob
int n,a[maxn],b[maxn],c[maxn],pt1,pt2,ans=0;
 
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(n) cin >> a[i];
	rep(n) cin >> b[i];
	rep(n) c[i]=a[i]-b[i];
	sort(c,c+n);
	pt1=0,pt2=n-1;
	rep(n) if(c[i]>0) ans--;
	while(pt1!=n){
		if(pt2==-1){
			ans+=n;
			pt1++;
		}
		else if(c[pt1]+c[pt2]>0) pt2--;
		else{
			ans+=n-pt2-1;
			pt1++;
		}
	}
	print1(ans>>1);
	return 0;
}