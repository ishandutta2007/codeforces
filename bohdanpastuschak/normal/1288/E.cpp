#include <bits/stdc++.h>
using namespace std;

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

const int N = 1 << 20;

int fw[N];

inline void add(int x, int y)
{
	for(; x < N; x |= x + 1)
		fw[x] += y;
}

inline int sum(int r)
{
	int res = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1)
		res += fw[r];
	return res;
}

inline int sum(int l, int r)
{
	if (l > r) return 0;
	return sum(r) - sum(l - 1);
}

int n, m;
int a[N];
PII ans[N];
int last[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	FOR(i, 1, n + 1) a[i] = n + 1 - i;
	FOR(i, 1, n + 1) ans[i] = {i, i};
	
	FOR(i, 1, m + 1) cin >> a[i + n];
	FOR(i, 1, m + 1) ans[a[i + n]].X = 1;
	
	FOR(i, 1, n + m + 1)
	{
		int x = a[i];
		add(i, 1);
		add(last[x], -1);		
		
		if (i > n) setmax(ans[x].Y, sum(last[x] + 1, i - 1) + 1);
		last[x] = i;
	}
	
	FOR(i, 1, n + 1) setmax(ans[i].Y, sum(last[i] + 1, N - 1) + 1);
			
	FOR(i, 1, n + 1) cout << ans[i].X << ' ' << ans[i].Y << '\n';
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}