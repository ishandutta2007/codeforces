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
 
const int maxn=300005;
//i_am_noob
int n,a[maxn],b[maxn],c[maxn],x=0,y=0;
vector<int> vec,ans[3];

bool comp(int i, int j){return a[i]<a[j];}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(n) cin >> a[i];
	rep(n) cin >> b[i];
	rep(n) c[i]=i;
	sort(c,c+n,comp);
	sort(b,b+n);
	rep(n){
		x+=a[c[i]],y+=b[i];
		if(x>y){
			print1("NO");
			return 0;
		}
		if(i==n-1&&x!=y){
			print1("NO");
			return 0;
		}
	}
	rep3(i,n-1,0) if(a[c[i]]>b[i]) vec.pb(i);
	x=0;
	while(1){
		if(x>=n||vec.empty()) break;
		y=vec.back();
		ans[0].pb(c[x]+1),ans[1].pb(c[y]+1),ans[2].pb(min(b[x]-a[c[x]],a[c[y]]-b[y]));
		a[c[x]]+=ans[2].back(),a[c[y]]-=ans[2].back();
		if(a[c[y]]==b[y]) vec.pop_back();
		while(a[c[x]]==b[x]){
			x++;
			if(x==n) break;
		}
	}
	print1("YES");
	print1(sz(ans[0]));
	rep(sz(ans[0])) print0(ans[0][i]),print0(ans[1][i]),print1(ans[2][i]);
	return 0;
}