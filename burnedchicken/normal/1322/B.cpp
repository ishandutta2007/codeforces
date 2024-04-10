#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=(int(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
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

const ll Mod=1000000007,Mod2=998244353;
const ll MOD=Mod;

inline ll add(ll a, ll b){return (a+b>=MOD?a+b-MOD:a+b);}
inline ll sub(ll a, ll b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
ll Pow(ll a, ll b){
	if(!b) return 1;
	ll tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline ll inverse(ll n){return Pow(n,MOD-2);}
ll dgts2(ll n){return (n?dgts2(n>>1)+1:0);}
ll dgts(ll n, ll k){return (n?dgts(n/k,k)+1:0);}
inline ll v2(ll n){return __builtin_ctzll(n);}

const int maxn=400005;
//i_am_noob
int n,a[maxn],ans=0,x,y;
ll cnt,cnt1,cnt2;
vector<int> vec,vec1,vec2,vec3,vec4,vec5;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(n) cin >> a[i];
	rep(n) vec.pb(0);
	rep(n) vec3.pb(i);
	rep(25){
		vec1.clear();
		vec2.clear();
		vec4.clear();
		vec5.clear();
		rep1(j,n){
			if(a[vec3[j]]&pow2(i)){
				vec2.pb(vec[j]|pow2(i));
				vec5.pb(vec3[j]);
			}
			else{
				vec1.pb(vec[j]);
				vec4.pb(vec3[j]);
			}
		}
		vec.clear();
		vec3.clear();
		rep1(j,sz(vec1)) vec.pb(vec1[j]);
		rep1(j,sz(vec2)) vec.pb(vec2[j]);
		rep1(j,sz(vec4)) vec3.pb(vec4[j]);
		rep1(j,sz(vec5)) vec3.pb(vec5[j]);
		x=0,y=sz(vec2)-1;
		cnt=0;
		while(x<sz(vec1)){
			if(y==-1){
				cnt=cnt+y+1;
				x++;
			}
			else if(vec1[x]+vec2[y]&pow2(i)){
				cnt=cnt+y+1;
				x++;
			}
			else{
				y--;
			}
		}
		cnt1=0;
		x=0,y=sz(vec1)-1;
		while(x<sz(vec1)){
			if(y==-1){
				cnt1=cnt1+sz(vec1)-1-y;
				x++;
			}
			else if(!(vec1[x]+vec1[y]&pow2(i))){
				cnt1=cnt1+sz(vec1)-1-y;
				x++;
			}
			else{
				y--;
			}
		}
		rep1(j,sz(vec1)) if((vec1[j]<<1)&pow2(i)) cnt1=cnt1-1;
		cnt1=cnt1>>1;
		cnt2=0;
		x=0,y=sz(vec2)-1;
		while(x<sz(vec2)){
			if(y==-1){
				cnt2=cnt2+sz(vec2)-1-y;
				x++;
			}
			else if(!(vec2[x]+vec2[y]&pow2(i))){
				cnt2=cnt2+sz(vec2)-1-y;
				x++;
			}
			else{
				y--;
			}
		}
		rep1(j,sz(vec2)) if((vec2[j]<<1)&pow2(i)) cnt2=cnt2-1;
		cnt2=cnt2>>1;
		if((cnt+cnt1+cnt2)&1) ans+=pow2(i);
	}
	print1(ans);
	return 0;
}