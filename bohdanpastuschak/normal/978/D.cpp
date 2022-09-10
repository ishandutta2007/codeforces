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

	int n; cin >> n;
	vector<int> a(n);
	FOR(i, 0, n) cin >> a[i];
	
	int ans = INF;
	if (n == 1) ans = 0;
	else{
		FOR(d1, -1, 2) FOR(d2, -1, 2){
			int curr = (d1 != 0) + (d2 != 0);
			int df = (a[1] + d2) - (a[0] + d1);

		
			int prv = a[1] + d2;
			FOR(i, 2, n){
				int zara = prv + df;				
				if (abs(a[i] - zara) > 1) curr = INF;
				else{
					if (zara != a[i])
						curr++;
						
					
				}

				prv += df;
			}
			
			setmin(ans, curr);
		}
	}

	cout << (ans == INF ? -1 : ans) << endl;	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}