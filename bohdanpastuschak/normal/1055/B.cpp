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

const int MAX = 1 << 17;
int n, m, l;
LL a[MAX];
int p[MAX];
int sz[MAX];
int ans = 0;

int find(int x)
{
	if (x == p[x])
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
	sz[x] += sz[y];
	p[y] = x;
	--ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> m >> l;
	FOR(i, 1, n + 1)
		cin >> a[i];
	
	FOR(i, 1, n + 1)
		p[i] = i, sz[i] = 0;
	
	FOR(i, 1, n)
		if (a[i] > l && a[i + 1] > l)
			unite(i, i + 1);
	ans = 0;
	set<int> S;
	FOR(i, 1, n + 1)
		if (a[i] > l)
			S.insert(find(i));
	ans = SZ(S);
	int t, p, d;
	while(m--)
	{
		cin >> t;
		if (t == 0)
			cout << ans << endl;
		else
		{
			cin >> p >> d;
			a[p] += d;
			if (a[p] - d > l)
				continue;
			
			if (a[p] > l)
			{
				++ans;
				if (p > 1 && a[p - 1] > l)
					unite(p, p - 1);
				
				if (p < n && a[p + 1] > l)
					unite(p, p + 1);
			}
		}
	}
	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}