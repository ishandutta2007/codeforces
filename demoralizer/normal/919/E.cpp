#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e6+5;

inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }

struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b)
{
	if (b == 0) return {1, 0, a};
	GCD_type pom = ex_GCD(b, a % b);
	return {pom.y, pom.x - a / b * pom.y, pom.d};
}

pair<int, int> CRT(vector<int> a, vector<int> &n)
{
	int t = a.size();
	int ans = a[0], lcm = n[0];
	for (int i = 1; i < t; ++i)
	{
		GCD_type pom = ex_GCD(lcm, n[i]);
		int x1 = pom.x;
		int d = pom.d;
		if ((a[i] - ans) % d != 0) return { -1, -1};
		ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * lcm, lcm * n[i] / d);
		lcm *= n[i] / d;
		// you can save time by replacing above lcm by lcm = lcm * n[i] / d
	}
	return {ans, lcm};
}
// a[i] = x mod n[i]
// returns {x mod lcm, lcm} or {-1, -1} for no solution
// time complexity O(t*log(LCM(n[])))

int32_t mod_inv(int32_t a, int32_t m) {
	int32_t g = m, r = a, x = 0, y = 1;
	while (r != 0) {
		int32_t q = g / r;
		g %= r; swap(g, r);
		x -= q * y; swap(x, y);
	}
	return x < 0 ? x + m : x;
}

void solve(){
	int a,b,p,x;
	cin>>a>>b>>p>>x;
	vector<int> vals = {1};
	rep(i,1,p-1){
		if(vals.back()*a%p == 1)continue;
		vals.pb(vals.back()*a%p);
	}
	vector<int> pr = {sz(vals),p};
	int f=0;
	rep(i,0,sz(vals)){
		int inv = mod_inv(vals[i],p);
		int j = b*inv%p;
		auto ans = CRT({i,j},pr);
		if(ans.fr == -1)continue;
		f += x/ans.sc;
		if(ans.fr <= x%ans.sc) f++;
	}
	cout<<f;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}