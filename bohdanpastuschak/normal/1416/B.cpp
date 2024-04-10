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

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		vector<int> a(n + 1, 0);
		FOR(i, 1, n + 1) cin >> a[i];
		int sum = accumulate(ALL(a), 0);
		if (sum % n){
			cout << "-1\n";
			continue;
		}

		int s = sum / n;
		vector<vector<int>> ans;

		vector<int> b;
		FOR(i, 2, n + 1){
			const int need = a[i] % i == 0 ? 0 : i - (a[i] % i);
			assert(a[1] >= need);
			ans.PB({1, i, need});
			a[1] -= need;
			a[i] += need;

			const int x = a[i] / i;
			ans.PB({i, 1, x});
			a[i] -= x * i;
			a[1] += x * i;
		}
		
		FOR(i, 2, n + 1){
			int need = s - a[i];
			assert(a[1] >= need);
			assert(need >= 0);
			ans.PB({1, i, need});
		}
		
		cout << SZ(ans) << '\n';
		for(auto i: ans){
			for(auto j: i) cout << j << ' ';
			cout << '\n';
		}						
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}