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

const int N = 1 << 20;
int n, m;
string s;

struct node
{
	int ans;
	int open;
	int close;
};

node t[N << 1];

node merge(node x, node y)
{
	int t = min(x.open, y.close);
	node res;
	res.ans = x.ans + y.ans + t;
	res.open = x.open + y.open - t;
	res.close = x.close + y.close - t;
	return res;
}

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		if (s[tl] == '(')
			t[v] = {0, 1, 0};
		else
			t[v] = {0, 0, 1};
	}
	else
	{
		int tm = (tl + tr) >> 1;
		build(2 * v, tl, tm);
		build(2 * v + 1, tm + 1, tr);
		t[v] = merge(t[2 * v], t[2 * v + 1]);
	}
}

node query(int v, int tl, int tr, int l, int r)
{
	if (l > r || tl > tr)
		return {0, 0, 0};
	
	if (l == tl && r == tr)
		return t[v];
	
	int tm = (tl + tr) >> 1;
	return merge(query(2 * v, tl, tm, l, min(tm, r)), 	
				query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> s;
	n = SZ(s);
	build(1, 0, n - 1);
	cin >> m;
	while(m--)
	{
		int l, r;
		cin >> l >> r;
		cout << 2*query(1, 0, n - 1, l - 1, r - 1).ans << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}