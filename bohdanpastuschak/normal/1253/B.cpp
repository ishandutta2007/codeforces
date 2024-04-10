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

const int N = 1 << 17;
int n;
int a[N];

void bad()
{
	cout << -1;
	exit(0);
}

void check(vector<int>& ans)
{
	if (SZ(ans) == 0) bad();
	FOR(i, 0, SZ(ans) - 1)
	{
		VI tut;
		FOR(j, ans[i], ans[i + 1]) tut.PB(a[j]);
		sort(ALL(tut));
		int sz = SZ(tut);
		tut.resize(unique(ALL(tut)) - tut.begin());
		if (SZ(tut) != sz) bad();
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	
	vector<int> ans;
	ans.PB(0);
	set<int> in;
	FOR(i, 0, n)
	{
		int tut = a[i];
		if (tut < 0)
		{
			if (!in.count(-tut)) bad();
			in.erase(-tut);
		}
		else
		{
			if (in.count(tut)) bad();
			in.insert(tut);
		}
		
		if (SZ(in) == 0)
			ans.PB(i + 1);
	}
	
	if (SZ(in)) bad();
	
	check(ans);
	RFOR(i, SZ(ans), 1)
		ans[i] -= ans[i - 1];
		
	cout << SZ(ans) - 1 << endl;
	FOR(i, 1, SZ(ans))
	{
		if (i > 1) cout << ' ';
		cout << ans[i];
	}
	
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}