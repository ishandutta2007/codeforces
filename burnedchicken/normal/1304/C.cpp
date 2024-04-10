#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=(int(a)); i--)
#define all(a) a.begin(),a.end()
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
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
#define printvec(a) rep(a.size()) print0(a[i])
#define debug(a) print2(#a,a)
 
using namespace std;
 
const ll Mod=1000000007,Mod2=998244353;
const ll MOD=Mod2;
 
inline ll add(ll a, ll b){return (a+b>=MOD?a+b-MOD:a+b);}
inline ll sub(ll a, ll b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
inline ll Pow(ll a, ll b){
	if(!b) return 1;
	ll tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline ll inverse(ll n){return Pow(n,MOD-2);}
ll dgts2(ll n){return (n?dgts2(n>>1)+1:0);}
ll dgts(ll n, ll k){return (n?dgts(n/k,k)+1:0);}
inline ll v2(ll n){return __builtin_ctzll(n);}
 
const int maxn=105;
//i_am_noob
ll q,n,m,x,y,k;
vector<ll> t,l,r;
bool ok;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> q;
	while(q--){
		cin >> n >> m;
		t.clear(),l.clear(),r.clear();
		t.pb(0),l.pb(m),r.pb(m);
		rep(n){
			cin >> x >> y >> k;
			if(x==t.back()){
				l.back()=max(l.back(),y);
				r.back()=min(r.back(),k);
			}
			else{
				t.pb(x),l.pb(y),r.pb(k);
			}
		}
		x=y=m;
		k=0;
		ok=true;
		rep(sz(t)){
			if(i==0) continue;
			x-=t[i]-k;
			y+=t[i]-k;
			k=t[i];
			if(l[i]>r[i]){
				ok=false;
				break;
			}
			if(y<l[i]||x>r[i]){
				ok=false;
				break;
			}
			x=max(x,l[i]);
			y=min(y,r[i]);
		}
		print1(ok?"YES":"NO");
	}
	return 0;
}