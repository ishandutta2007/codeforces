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

int n, m;
inline bool ok(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		FOR(i, 0, n) FOR(j, 0, m) cin >> a[i][j];
		auto b = a;
		FOR(i, 0, n) FOR(j, 0, m){
			int& x = b[i][j];
			x = 0;
			FOR(k, 0, 4){
				int I = i + dx[k], J = j + dy[k];
				x += ok(I, J);
			}
		}
					
		bool ok = 1;
		FOR(i, 0, n) FOR(j, 0, m) ok &= b[i][j] >= a[i][j];
		if (!ok){
			cout << "NO" << '\n';
			continue;
		}
		
		cout << "YES" << '\n';
		FOR(i, 0, n){
			FOR(j, 0, m) cout << b[i][j] << ' ';
			cout << '\n';
		}
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}