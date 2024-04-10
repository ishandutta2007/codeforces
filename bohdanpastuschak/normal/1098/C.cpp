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
const LL INF = 1e9;
const LL LINF = INF * INF;

const int MAX = 1 << 17;

LL min_s(LL n, int k)
{
	if (k == 1)
		return n * (n + 1) / 2;
	
	LL pw = 1;
	LL res = 0;
	int level = 1;
	while(n > 0)
	{
		res += min(n, pw) * level;
		n -= pw;
		pw *= k;
		level++;
	}
	
	return res;
}

int batya[MAX];
int g[MAX];
int depth[MAX];
set<PII> lystky;

int dp[MAX];
VI G[MAX];
bool W[MAX];

void dfs(int v)
{
	W[v] = 1;
	for(auto i: G[v])
	{
		dp[i] = dp[v] + 1;
		dfs(i);
	}
}

pair<LL, int> checker(int n)
{
	int mx = 0;
	FOR(i, 2, n + 1)
		G[batya[i]].PB(i);
	
	FOR(i, 1, n + 1)
		mx = max(mx, SZ(G[i]));
	
	dp[1] = 1;
	dfs(1);
	LL ans = 0;
	FOR(i, 1, n + 1)
		ans += dp[i];
	
	return {ans, mx};
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	LL n, s;
	cin >> n >> s;
	LL SS = s;
	
	LL mi = n + n - 1;
	LL ma = n * (n + 1) / 2;
	if (s > ma || s < mi)
	{
		cout << "No" << endl;
		return 0;
	}
	
	cout << "Yes" << endl;
	if (s == ma)
	{
		FOR(i, 2, n + 1)
		{
			if (i > 2)
				cout << ' ';
			cout << i - 1;
		}
		
		cout << endl;
		return 0;
	}
	
	int ans = 1;
	while(s < min_s(n, ans))
		++ans;

	s -= min_s(n, ans);	
	int zara = 2;
	depth[1] = 1;
	FOR(i, 1, n + 1)
	{
		FOR(j, 0, ans)
		{
			if (zara > n)
				break;
			g[i]++;
			batya[zara] = i;
			depth[zara] = depth[i] + 1;
			++zara;
		}
	}
	
	FOR(i, 1, n + 1)
		if (g[i] == 0)
			lystky.insert({depth[i], i});
	
	int ost = depth[n];
	while(s > 0)
	{
		PII beg = *lystky.begin();
		lystky.erase(beg);
		
		int v = beg.Y;
		int je = depth[v];
		int bude = ost + 1;
		int add = bude - je;
		//cout << add << ' ' << bude << ' ' << je << endl;
	
		if (add <= s)
		{
			PII last = *lystky.rbegin();
			lystky.erase(last);
			s -= add;
			g[last.Y]++;
			lystky.insert({bude, v});
			int bat = batya[v];
			g[bat]--;
			if (g[bat] == 0)
				lystky.insert({depth[bat], bat});
			
			ost++;
			batya[v] = last.Y;
			depth[v] = bude;
			continue;
		}
		
		
		bool bulo = 0;
		int maje = s + je;
		FOR(i, 1, n + 1)
			if (i != v && depth[i] == maje - 1 && g[i] < ans)
			{
				bulo = 1;
				batya[v] = i;
				break;
			}
		
		assert(bulo);
		break;
	}
	
	checker(n);
			FOR(i, 1, n + 1)
				assert(W[i]);
	
//	auto ch = checker(n);
//	assert(ch.X == SS);
//	assert(ch.Y == ans);
//	
	FOR(i, 2, n + 1)
	{
		if (i > 2)
			cout << ' ';
		cout << batya[i];
	}
	
	cout << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}