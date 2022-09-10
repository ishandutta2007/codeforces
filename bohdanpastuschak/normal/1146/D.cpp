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
#define endl '\n'
const double PI = acos(-1.0);
const LL INF = 1e9 + 447;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, a, b, d;
int L, R;

LL F(int l1)
{
	return l1 * (LL)(l1 + 1) / 2;
}

LL f(int l1, int r1)
{
	return F(r1) - F(l1 - 1);
}

LL get()
{
	LL ans = 0;
	d = __gcd(a, b);
	L = a + b, R = n;
	if (L > R)
		return 0;
		
	LL POC = L - 1;
	POC = POC / d ;
	while(L <= R && (L % d != 0))
	{
		ans += L / d - POC;
		++L;
	}
	
	while(L <= R && (R % d != d - 1))
	{
		ans += R / d - POC;
		--R;
	}
	
	if (L > R)
		return ans;
	
	LL beg = L / d, en = R / d;
	beg -= POC;
	en -= POC;
	LL tut = f(beg, en);	
	ans += tut * d;
	return ans;
}

const int N = 1 << 18;
int l[N];
int IT = 0;

void dfs(int v)
{
	++IT;
	if (v >= b)
	{
		if (l[v] < l[v - b])
		{
			l[v - b] = l[v];
			dfs(v - b);
		}
	}
	
	if (v + a < N && max(v + a, l[v]) < l[v + a])
	{
		l[v + a] = max(l[v], v + a);
		dfs(v + a);
	}		
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> a >> b;
	LL ans = 0;
	FOR(i, 0, N)
		l[i] = INF;
	l[0] = 0;
	dfs(0);
	FOR(i, 0, a + b)
	{
		if (i > n)
			break;
		ans += max(0, n - l[i] + 1);
	}

	ans += get();
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}