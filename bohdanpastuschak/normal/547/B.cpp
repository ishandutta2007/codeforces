#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
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
int n;
int a[N];
int p[N];
PII b[N];
int sz[N];
int ans[N];
char je[N];

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
	if (x == y)
		return;
	
	if (sz[x] < sz[y])
		swap(x, y);
	p[y] = x;
	sz[x] += sz[y];
}

void onowy(int& x, int y)
{
	x = max(x, y);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i];
		b[i] = {a[i], i};
	}
	
	sort(b, b + n);
	reverse(b, b + n);
	
	FOR(i, 0, n)
		p[i] = i, sz[i] = 1;
	
	FOR(i, 0, n)
	{
		int id = b[i].Y, h = b[i].X;
		je[id] = 1;
		if (id && je[id - 1])
			unite(id, id - 1);
		if (je[id + 1])
			unite(id, id + 1);
		
		onowy(ans[sz[find(id)]], h);		
	}
	
	RFOR(i, n, 1)
		ans[i] = max(ans[i], ans[i + 1]);
		
	FOR(i, 1, n + 1)
		cout << ans[i] << ' ';
	cout << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}