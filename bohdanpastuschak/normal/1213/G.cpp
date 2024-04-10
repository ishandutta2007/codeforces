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

const int N = 1 << 18;
int n, m;
pair<int, PII> e[N];
PII q[N];
LL ans[N];
int sz[N];
int p[N];
LL curr;

int find(int x)
{
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	assert(x != y);
	if (sz[x] < sz[y])	
		swap(x, y);
	
	p[y] = x;
	curr += sz[x] * (LL) sz[y];
	sz[x] += sz[y];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 0, n - 1)
		cin >> e[i].Y.X >> e[i].Y.Y >> e[i].X;
	
	FOR(i, 0, m)
		cin >> q[i].X, q[i].Y = i;
	
	sort(q, q + m);
	sort(e, e + n - 1);
	
	FOR(i, 1, n + 1)
		p[i] = i, sz[i] = 1;
	
	int ptr = 0;
	FOR(i, 0, m)
	{
		while(ptr < n - 1 && e[ptr].X <= q[i].X)
			unite(e[ptr].Y.X, e[ptr].Y.Y), ptr++;
		
		ans[q[i].Y] = curr;
	}
	
	FOR(i, 0, m)
		cout << ans[i] << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}