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

const int N = 1 << 19;
int n;
int a[N];
int p[N];
int start;
bool ok;

inline void solve(int l, int r)
{
	if (l > r)
		return;
	
	if (l == r)
	{
		if (a[l] > l + 1)
		{
			ok = 0;
			return;
		}
		p[l] = start++;
		return;
	}
	
	int now = l;
	while(now <= r)
	{
		int bude = a[now];
		if (bude > r + 1)
		{
			ok = false;
			return;
		}
		
		solve(now + 1, bude - 1);
		now = bude;
	}
	
	now = l;
	p[now] = start++;
	while(now <= r)
	{
		now = a[now];
		if (now > r)
			break;
		p[now] = start++;
	}
		
	solve(now + 1, r);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		FOR(i, 1, n + 1)
		{
			cin >> a[i];
			if (a[i] == -1)
				a[i] = i + 1;
		}
		
		start = 1;
		ok = 1;
		solve(1, n);		
		if (!ok)
		{
			cout << -1 << endl;
			continue;
		}
		
		FOR(i, 1, n + 1)
		{
			if (i > 1)
				cout << ' ';
			cout << p[i];
		}
		
		sort(p + 1, p + n + 1);
		FOR(i, 1, n + 1)
			assert(p[i] == i);
		cout << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}