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
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int k;

inline int mult(int x, int y)
{
	return x * (LL) y % k;
}

const int N = 1 << 17;
int n;
int a[N];
int t[N << 1];

void build(int v, int tl, int tr)
{
	if (tl == tr)
		t[v] = a[tl] % k;
	else
	{
		int tm = tl + tr >> 1;
		build(2 * v, tl, tm);
		build(2 * v + 1, tm + 1, tr);
		t[v] = mult(t[v * 2], t[v * 2 + 1]);
	}
}

int get(int v, int tl, int tr, int l, int r)
{
	if (l > r || tl > tr)
		return 1;
	
	if (l == tl && r == tr)
		return t[v];
	
	int tm = tl + tr >> 1;
	return mult(get(2 * v, tl, tm, l, min(r, tm)),
		get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> k;
	FOR(i, 0, n)
		cin >> a[i];
	
	build(1, 0, n - 1);
	LL ans = 0;
	
	int ptr = 0;
	FOR(i, 0, n)
	{
		ptr = max(ptr, i);
		while(ptr < n && get(1, 0, n - 1, i, ptr))
			ptr++;
		ans += n - ptr;
	}
	
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}