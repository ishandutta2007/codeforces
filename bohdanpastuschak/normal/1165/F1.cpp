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
int k[N];
VI tut[N];

bool ok(int x)
{
	int treba_v_ost = 0;
	vector<PII> last;
	FOR(i, 0, n)
	{
		if (SZ(tut[i]) == 0 || tut[i][0] > x)
		{
			treba_v_ost += k[i] * 2;
			continue;
		}
		
		auto it = upper_bound(ALL(tut[i]), x) - tut[i].begin() - 1;
		last.PB(MP(tut[i][it], k[i]));
	}
	
	sort(ALL(last));
	int used = 0;
	
	for(auto i: last)
	{
		int chas = i.X, kst = i.Y;
		if (!kst)
			continue;
		//cout << chas << ' ' <<kst << endl;
		int mx = chas - used;
		mx = min(mx, kst);
		
		treba_v_ost += mx;
		kst -= mx;
		used += mx;
		
		treba_v_ost += kst * 2;
	}
	
	//cout << x << ' ' << treba_v_ost << endl;
	
	return treba_v_ost <= x;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 0, n)
		cin >> k[i];
	
	FOR(i, 0, m)
	{
		int d, t;
		cin >> d >> t;
		--t;
		tut[t].PB(d);
	}
	
	FOR(i, 0, n)
		sort(ALL(tut[i]));
	
	int L = 0, R = 2 * N;
	while(R - L > 1)
	{
		int M = (L + R) >> 1;
		if (ok(M))
			R = M;
		else
			L = M;
	}
	
	int ans;
	if (ok(L))
		ans = L;
	else
		ans = R;
	
	assert(ok(ans));
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}