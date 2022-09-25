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
int n,ans=0,l=4e18,r=-4e18,k;
ordered_set st;
vector<int> vec;
bool flag;

struct point{int x,y;}p[maxn];
bool comp(point p1, point p2){return p1.y!=p2.y?p1.y>p2.y:p1.x<p2.x;}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(n) cin >> p[i].x >> p[i].y;
	sort(p,p+n,comp);
	rep(n){
		flag=false;
		st.insert(p[i].x);
		vec.pb(p[i].x);
		if(i==n-1) flag=true;
		else if(p[i].y>p[i+1].y) flag=true;
		if(flag){
			ans+=sz(st)*(sz(st)+1)/2;
			k=st.order_of_key(vec[0]);
			ans-=k*(k+1)/2;
			k=sz(st)-st.order_of_key(vec.back())-1;
			ans-=k*(k+1)/2;
			rep1(j,sz(vec)-1){
				k=st.order_of_key(vec[j+1])-st.order_of_key(vec[j])-1;
				ans-=k*(k+1)/2;
			}
			vec.clear();
		}
	}
	print1(ans);
	return 0;
}