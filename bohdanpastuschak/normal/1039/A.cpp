#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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

const double PI = acos(-1.0);
const LL II = 1e9;
const LL INF = 3 * II * II;
const LL LINF = 4e18 + 47;

LL n, T;
const int MAX = 2e5 + 47;
LL a[MAX];
LL b[MAX];
LL x[MAX];

void bad()
{
	cout << "No" << endl;
	exit(0);
}

LL up[MAX];
LL down[MAX];

int t[MAX << 2];

void update (int v, int tl, int tr, int l, int r) 
{
	if (l > r || tl > tr)
		return;
	
	if (l == tl && tr == r)
		t[v]++;
	else 
	{
		int tm = (tl + tr) >> 1;
		update (v << 1, tl, tm, l, min(r,tm));
		update ((v << 1) | 1, tm+1, tr, max(l,tm+1), r);
	}
}
 
int get (int v, int tl, int tr, int pos) 
{
	if (tl == tr)
		return t[v];
	
	int tm = (tl + tr) >> 1;
	
	if (pos <= tm)
		return t[v] + get (v << 1, tl, tm, pos);
	else
		return t[v] + get ((v << 1) | 1, tm+1, tr, pos);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> T;
	FOR(i, 1, n + 1)
		cin >> a[i];
	
	FOR(i, 1, n + 1)
		cin >> x[i];
	
	FOR(i, 1, n + 1)
		if (x[i] < i)
			bad();
	
	FOR(i, 1, n + 1)
		down[i] = 1, up[i] = LINF;
		
	
	FOR(i, 1, n + 1)
		down[i] = max(down[i], a[i] + T);
	
	FOR(i, 1, n + 1)
		update(1, 0, n - 1, i - 1, x[i] - 2);
	
	FOR(i, 1, n)
		if (get(1, 0, n - 1, i - 1))
			down[i] = max(down[i], a[i + 1] + T);
	
	
	FOR(i, 2, n + 1)
		down[i] = max(down[i], down[i - 1] + 1);
	
	FOR(i, 1, n + 1)
		if (x[i] < n)
			up[x[i]] = min(up[x[i]], a[x[i] + 1] + T - 1);
	
	FOR(i, 1, n + 1)
		if (down[i] > up[i])
			bad();
	
	if (down[n] > INF)
		bad();
	
	cout << "Yes" << endl;
	FOR(i, 1, n + 1)
		cout << down[i] << " ";
	cout << endl;
	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}