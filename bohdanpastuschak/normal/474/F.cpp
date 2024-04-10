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
int t[MAX << 1];
int a[MAX];
int n;
map<int, VI> mp;

int get(int x, int l, int r)
{
	auto it = lower_bound(ALL(mp[x]), l);
	auto it2 = upper_bound(ALL(mp[x]), r);
	return abs(distance(it, it2));
}

void build(int v, int tl, int tr)
{
	if (tl == tr)
		t[v] = a[tl];
	else
	{
		int tm = (tl + tr) >> 1;
		build(v << 1, tl, tm);
		build((v << 1) | 1, tm + 1, tr);
		t[v] = __gcd(t[v << 1], t[(v << 1) | 1]);
	}
}

int get(int v, int tl, int tr, int l, int r)
{
	if (l > r || tl > tr)
		return 0;
	
	if (l == tl && r == tr)
		return t[v];
	
	int tm = (tl + tr) >> 1;
	return __gcd(get(v << 1, tl, tm, l, min(r, tm)), get((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r));
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i];
		mp[a[i]].PB(i);
	}
	
	build(1, 0, n - 1);
	
	int T;
	cin >> T;
	while(T--)
	{
		int l, r;
		cin >> l >> r;
		--l; --r;
		
		int G = get(1, 0, n - 1, l, r);
		cout << r - l + 1 - get(G, l, r) << endl;
	}

	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}