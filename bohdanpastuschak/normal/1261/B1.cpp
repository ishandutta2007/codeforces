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
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
int n, m;
int a[N];
PII b[N];
vector<PII> Q[N];
int ans[N];

int cmp(PII x, PII y)
{
	if (x.X != y.X) return x.X > y.X;
	return x.Y < y.Y;
}

int ft[N];

void add(int x)
{
	for(; x < n; x |= x + 1) ft[x]++;
}

int sum(int r)
{
	int res = 0;
	for(; r >= 0; r =(r & (r + 1)) - 1) res += ft[r];
	return res;
}

int sum(int l, int r)
{
	return sum(r) - sum(l - 1);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	FOR(i, 0, n) b[i] = {a[i], i};
	sort(b, b + n, cmp);	
	cin >> m;
	FOR(i, 0, m)
	{
		int pos, k;
		cin >> k >> pos;
		Q[k].PB({pos, i});
	}
	
	FOR(it, 0, n)
	{
		add(b[it].Y);
		for(auto i: Q[it + 1])
		{
			int l = -1, r = n - 1;
			while(r - l > 1)
			{
				int med = (l + r) >> 1;
				if (sum(0, med) >= i.X) r = med;
				else l = med;				
			}
			
			ans[i.Y] = a[r];
		} 
	}	
	
	FOR(i, 0, m) cout << ans[i] << '\n';	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}