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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		FOR(i, 0, n) cin >> a[i];
		int o = 0, e = 0, su = 0;
		FOR(i, 0, n){
			if (a[i] % 2 == 0) e++;
			else o++;
			su += a[i];
		}
		
		bool ok = false;
		
		if (o == 0) ok = false;
		else{
			if (e == 0){
				if (x % 2 == 0) ok = false;
				else ok = true;
			}else{
				if (x == n){
					if (su % 2 == 0) ok = false;
					else ok = true;
				}else{
					ok = true;
				}
			}
		}
		cout << (ok ? "Yes\n" : "No\n");
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}