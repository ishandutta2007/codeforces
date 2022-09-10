#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long double db;

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

template<typename T> void print(const T& a, ostream& out){	
	for(auto i: a) out << i << ' ';
	out << endl;
}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const db EPS = 1e-9;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	while(tc--){
		int n, l; cin >> n >> l;
		vector<int> a(n + 2);
		a[0] = 0;
		a[n + 1] = l;
		FOR(i, 1, n + 1) cin >> a[i];

		vector<db> t1(n + 2);
		t1[0] = 0;
		FOR(i, 1, n + 1){
			t1[i] = t1[i - 1] + (a[i] - a[i - 1]) / (db) i;
		}

		vector<db> t2(n + 2);
		t2[n + 1] = 0;
		RFOR(i, n + 1, 1){
			t2[i] = t2[i + 1] + (a[i + 1] - a[i]) / (db)(n + 1 - i);
		}

		bool found = false;
		FOR(i, 0, n + 1){
			if (t1[i] <= t2[i] + EPS && t2[i + 1] <= t1[i + 1] + EPS){
				found = true;
				const db curr = max(t1[i], t2[i + 1]);
				
				db pos1 = a[i], pos2 = a[i + 1];
				pos1 += (curr - t1[i]) * (i + 1);
				pos2 -= (curr - t2[i + 1]) * (n + 1 - i);
				
				db ans = curr;
				ans += (pos2 - pos1) / (n + 2);
				cout << fixed << setprecision(10) << ans << endl;
				break;
			}
		}

		assert(found);
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}