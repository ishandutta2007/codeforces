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
		int n;
		cin >> n;
		vector<int> a(n);
		FOR(i, 0, n) cin >> a[i];
		
		int cntp = 0, cntm = 0;
		FOR(i, 1, n){
			if (a[i] == a[i - 1]) cntp++, cntm++;
			else if (a[i] > a[i - 1]) cntp++;
			else cntm++;
		}
		
		const int N = (n - 1) / 2;
		while(cntp < N){
			FOR(i, 1, n){
				int tut = 0;
				tut += a[i] >= a[i - 1];
				tut += (i < n - 1) && a[i + 1] >= a[i];
				int bude = 0;
				bude += -a[i] >= a[i - 1];
				bude += (i < n - 1) && a[i + 1] >= -a[i];
				
				if (bude > tut){
					cntp += bude - tut;
					a[i] = -a[i];
					break;
				}
			}
		}
		
		while(cntm < N){
			FOR(i, 1, n){
				int tut = 0;
				tut += a[i] <= a[i - 1];
				tut += (i < n - 1) && a[i + 1] <= a[i];
				int bude = 0;
				bude += -a[i] <= a[i - 1];
				bude += (i < n - 1) && a[i + 1] <= -a[i];
				
				if (bude > tut){
					cntm += bude - tut;
					a[i] = -a[i];
					break;
				}
			}
		}
		
		FOR(i, 0, n) cout << a[i] << ' ';
		cout << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}