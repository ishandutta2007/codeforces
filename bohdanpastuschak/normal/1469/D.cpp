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

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<PII> ans;
		vector<int> a(n + 1);
		iota(ALL(a), 0);

		if (n == 3){
			ans.PB({3, 2});
			ans.PB({3, 2});
		}else{

			if (n <= 256){
				FOR(i, 3, n){
					ans.PB({i, n});
				}

				int curr = n;
				while(curr > 1){
					ans.PB({n, 2});
					curr = (curr + 1) / 2;
				}
			}else{
				if (n <= 32768){
					FOR(i, 3, n) if (i != 8){
						ans.PB({i, n});
					}

					int curr = n;
					while(curr > 1){
						ans.PB({n, 8});
						curr = (curr + 7) / 8;
					}

					FOR(i, 0, 4){
						ans.PB({8, 2});
					}
				}else{
					FOR(i, 3, n) if (i != 16 && i != 4){
						ans.PB({i, n});
					}

					int curr = n;
					while(curr > 1){
						ans.PB({n, 16});
						curr = (curr + 15) / 16;
					}

					FOR(i, 0, 2){
						ans.PB({16, 4});
					}

					FOR(i, 0, 2){
						ans.PB({4, 2});
					}						
				}
			}
		}
	
		for(auto i: ans){
			a[i.X] = (a[i.X] + a[i.Y] - 1) / a[i.Y];
		}

		sort(ALL(a));
		assert(a[n - 1] == 1 && a[n] == 2);
		assert(SZ(ans) <= n + 5);
		cout << SZ(ans) << '\n';
		for(auto i: ans){
			cout << i.X << ' ' << i.Y << '\n';
		}		
	}
	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}