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
		vector<int> a(n);
		FOR(i, 0, n) cin >> a[i];
		LL ans = 0;
		//FOR(i, 0, n) FOR(j, 0, i) FOR(k, 0, j) if (a[i] == a[k]) FOR(l, 0, k) ans += a[l] == a[j];

		vector<vector<int>> s(n, vector<int>(n, 0));
		FOR(i, 0, n) FOR(j, i + 2, n) if (a[i] == a[j]) s[i][j]++;
		
		vector<vector<int>> suf_sum(n + 1, vector<int>(n + 1, 0));
		FOR(i, 0, n){
			RFOR(j, n, 0){
				suf_sum[i][j] += suf_sum[i][j + 1];
				suf_sum[i][j] += s[i][j];
			}
		}

		vector<vector<int>> f(n, vector<int>(n, 0));
		
		FOR(j, 0, n){
			vector<int> S(n);
			FOR(i, 0, n) S[i] = suf_sum[i][j + 1];
			vector<int> F(n, 0);

			RFOR(i, j, 0){
				F[i] += F[i + 1];
				if (i) F[i - 1] += S[i];
			}
			
			FOR(i, 0, n) f[i][j] = F[i];
		}

		FOR(i, 0, n) FOR(j, i + 2, n) if (a[i] == a[j]){
			ans += f[i][j];
			//FOR(k, i + 1, j) ans += suf_sum[k][j + 1];
		}
		
		cout << ans << endl;
	}	
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}