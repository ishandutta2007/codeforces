#include <bits/stdc++.h>
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;
 
template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}
 
const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;

inline LL get(int x){
	return x * (LL) (x + 1) / 2;
}

inline LL get(int last, int x){
	return last * (LL) x - x * (LL) (x - 1) / 2;
}

inline LL get(int l, int r, vector<LL>& a){
	if (l > r) return 0;
	LL res = a[r];
	if (l) res -= a[l - 1];
	return res;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  	
  	LL x;
	int n;
	cin >> n >> x;
	vector<int> a(n);  		
	FOR(i, 0, n) cin >> a[i];
	
	LL ans = 0;
	FOR(it, 0, 2){
		a.resize(n + n);
		FOR(i, 0, n) a[i + n] = a[i];
		vector<LL> pref(n + n);
		vector<LL> G(n);
		FOR(i, 0, n){
			G[i] = get(a[i]);
		}
		
		vector<LL> P(n + n);
		P[0] = a[0];
		FOR(i, 1, n + n){
			P[i] = P[i - 1] + a[i];
		}
		
		pref[0] = G[0];
		FOR(i, 1, n + n){
			pref[i] = pref[i - 1] + G[i % n];
		}
		
		FOR(i, 0, n){
			LL vje = i == 0 ? 0 : P[i - 1];
			auto it = upper_bound(ALL(P), vje + x) - P.begin();
			
			LL curr = get(i, it - 1, pref);
			LL she = x -  get(i, it - 1, P);
			if (it == 0) curr += get(she);
			else curr += get(a[it], she);			
			//debug(curr)
			setmax(ans, curr);
		}
		
		reverse(ALL(a));
	}
	//debug(ans)
	cout << ans << endl;
  	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}