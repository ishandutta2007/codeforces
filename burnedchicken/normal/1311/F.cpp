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

const int maxn=200005;
//i_am_noob
int n;
ll ans=0;
struct point{int x,v;}a[maxn];
bool comp(point p1, point p2){return p1.x<p2.x;}
bool comp2(point p1, point p2){return p1.v!=p2.v?p1.v<p2.v:p1.x<p2.x;}

struct BIT{
	ll val[maxn];
	void modify(int x, int y){for(int i=x; i<maxn; i+=i&-i) val[i]+=y;}
	ll query(int x, int y){
		ll ret=0;
		for(int i=y; i>0; i-=i&-i) ret+=val[i];
		for(int i=x-1; i>0; i-=i&-i) ret-=val[i];
		return ret;
	}
}b1,b2;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(n) cin >> a[i].x;
	rep(n) cin >> a[i].v;
	sort(a,a+n,comp2);
	rep(n) a[i].v=i+1;
	sort(a,a+n,comp);
	fill(b1.val,b1.val+n+1,0);
	fill(b2.val,b2.val+n+1,0);
	rep(n){
		b1.modify(a[i].v,a[i].x);
		b2.modify(a[i].v,1);
		if(a[i].v>1){
			ans+=a[i].x*b2.query(1,a[i].v-1)-b1.query(1,a[i].v-1);
		}
	}
	print1(ans);
	return 0;
}