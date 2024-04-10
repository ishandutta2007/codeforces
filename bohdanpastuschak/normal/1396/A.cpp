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

inline void get(LL x, int n, LL& k, LL& l){
	bool was = 0;
	
	if (x < 0){
		x = -x;
		was = 1;
	}
	
	LL A = (x + n - 1) / n;
	LL B = A * n - x;
	k = A - B;
	l = B;
	
	if (was){
		k = -k;
		l = -l;
	}
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<LL> a(n);
	FOR(i, 0, n) cin >> a[i];

	vector<LL> k(n), l(n);
	FOR(i, 0, n){
		get(a[i], n, k[i], l[i]);
	}

	cout << 1 << ' ' << n << endl;
	FOR(i, 0, n){
		cout << -n * (LL) k[i] << ' ';
	}
	cout << endl;

	if (n == 1){
		FOR(it, 0, 2){
			cout << 1 << ' ' << n << endl;
			FOR(i, 0, n){
				cout << 0 << ' ';
			}
			cout << endl;
		}

		return 0;
	}

	cout << 1 << ' ' << n - 1 << endl;
	FOR(i, 0, n - 1){
		cout << -(n - 1) * (LL) l[i] << ' ';
	}
	cout << endl;

	cout << 2 << ' ' << n << endl;
	FOR(i, 1, n){
		if (i == n - 1){
			cout << -(n - 1) * (LL)l[i] << ' ';
		}else cout << 0 << ' ';
	}

	cout << endl;
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}