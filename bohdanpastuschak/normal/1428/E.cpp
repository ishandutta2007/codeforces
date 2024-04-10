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

const int N = 1 << 17;
int n, k;
int a[N];
int c[N];

inline LL calc(int A, int C){
	int K = A / C;
	int cnt2 = A - K * C;
	int cnt1 = C - cnt2;
	return K * (LL) K * cnt1 + (K + 1) * (LL) (K + 1) * cnt2;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> k;
	FOR(i, 0, n) cin >> a[i], c[i] = 1;
	set<pair<LL, int>> diff;
	FOR(i, 0, n){
		LL now = calc(a[i], c[i]);
		LL will = calc(a[i], c[i] + 1);
		diff.insert({now - will, i});
	}

	FOR(iter, 0, k - n){
		auto it = diff.end();
		--it;
		int i = it->Y;
		diff.erase(it);
		c[i]++;
		LL now = calc(a[i], c[i]);
		LL will = calc(a[i], c[i] + 1);
		diff.insert({now - will, i});
	}
	
	LL ans = 0;
	FOR(i, 0, n) ans += calc(a[i], c[i]);
	cout << ans << endl;
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}