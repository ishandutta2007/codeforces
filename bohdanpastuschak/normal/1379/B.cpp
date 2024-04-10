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

inline void get(int l, int r, LL x, int& b, int& c){
	assert(l - r <= x && x <= r - l);
	FOR(i, l, r + 1){
		b = i;
		c = b - x;
		if (l <= c && c <= r) return;
	}

	assert(0);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		LL l, r, m;
		cin >> l >> r >> m;
		int Len = r - l;
		FOR(A, l, r + 1){
			if (m - A >= -Len){
				if (m - A <= Len){
					cout << A << ' ';
					int b, c;
					get(l, r, m - A, b, c);
					cout << b << ' ' << c << endl;
					break;
				}else{
					if (m % A <= Len){
						cout << A << ' ';
						int b, c;
						get(l, r, m % A, b, c);
						cout << b << ' ' << c << endl;
						break;
					}else{
						if ((m % A) - A >= -Len){
							cout << A << ' ';
							int b, c;
							get(l, r, (m % A) - A, b, c);
							cout << b << ' ' << c << endl;
							break;
						}
					}
				}
			}
		}
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}