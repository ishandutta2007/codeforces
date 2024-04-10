//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
	c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fastio;

	int n, d;
	cin>>n>>d;

	ll a[n];
	ll period[10] = {0};
	period[0] = 1;
	period[1] = 1;
	forsn(i,2,10){
		ll x = (i*i)%10;
		ll per = 1;
		while(x != i){
			x = (x*i)%10;
			per++;
		}
		period[i] = per;
	}
	vp64 v[10];

	forn(i,n){
		cin>>a[i];
		int l = a[i]%10;
		v[l].pb(mp(a[i], i));
	}
	forn(i,10) sort(all(v[i]));
	ld mi = 1e18;
	v64 min_prod;
	v64 remmed;
	ll obl[10] = {0};

	forn(i,10){
		if(i%2 == 0 || i%5 == 0){
			if((i%2 == 0) && (d%2 != 0)) obl[i] = 1;
			if((i%5 == 0) && (d%5 != 0)) obl[i] = 1;
		}
		// if(v[i].size() == 0) obl[i] = 1;
	}

	forn(i,1<<20){
		ll pos[10] = {0};
		ll x = i;
		int cnt = 0;
		while(x){
			pos[cnt] = x%period[cnt];
			if(obl[cnt]) pos[cnt] = v[cnt].size()%period[cnt];
			x /= 4;
			cnt++;
		}
		ll last = 1;
		forn(i,10){
			ll f = 1;
			if(obl[i] == 0){
				ll x = (v[i].size() % period[i]) - pos[i];
				if(x < 0) x += period[i];
				if((int)v[i].size() - x > 0){
					forn(j,period[i]+pos[i]){
						f = (f * i) % 10;
					}
				}
			}
			last = (last * f) % 10;
		}
		// cout<<last<<ln;
		if(last != d) continue;
		ld mul = 0;
		bool p = 1;
		forn(i,10){
			if(v[i].size()<pos[i]) p = 0;
		}
		if(p == 0) continue;
		ll rem[10] = {0};
		v64 tkn;
		forn(j,10){
			ll x = (v[j].size() % period[j]) - pos[j];
			if(x < 0) x += period[j];
			rem[j] = x;
			// if(i == 0) cout<<j<<" "<<rem[j]<<ln;
		}
		forn(i,10){
			forn(j,rem[i]){
				mul += log(v[i][j].fi);
				tkn.pb(v[i][j].se);
			}
		}
		if(tkn.size() == n) continue;
		if(mul < mi){
			mi = mul;
			swap(min_prod, tkn);
		}
	}

	if(mi == 1e18){
		cout<<-1<<ln;
	}
	else{
		int ntk[n] = {0};
		forstl(r, min_prod) ntk[r] = 1;
		forn(i,n){
			if(obl[a[i]%10]) ntk[i] = 1;
		}
		ll tk = 0;
		forn(i,n){
			if(ntk[i]) continue;
			tk++;
		}
		if(tk == 0){
			cout<<-1<<ln;
		}
		else{
			cout<<tk<<ln;
			forn(i,n){
				if(ntk[i]) continue;
				cout<<a[i]<<" ";
			}
			cout<<ln;
		}
	}

	return 0;
}