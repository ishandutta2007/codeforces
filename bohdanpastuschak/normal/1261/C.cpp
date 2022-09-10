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

const int N = 1 << 20;
int n, m;
string s[N];
vector<int> d[N];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
vector<int> d2[N];

inline bool ok(int x, int y)
{
	return x >= 0 && y >= 0 && x <= n + 1 && y <= m + 1;
}

bool ok(int dst)
{
	FOR(i, 0, n + 2) d2[i].assign(m + 2, -1);
	queue<PII> q;
	FOR(i, 0, n + 2) FOR(j, 0, m + 2) if (s[i][j] == 'X' && d[i][j] > dst)
	{
		q.push({i, j});
		d2[i][j] = 0;
	}

	while(!q.empty())
	{
		int x = q.front().X;
		int y = q.front().Y;
		q.pop();
		
		FOR(k, 0, 8)
		{
			int i = x + dx[k];
			int j = y + dy[k];
			if (!ok(i, j) || d2[i][j] != -1) continue;
			d2[i][j] = d2[x][y] + 1;
			q.push({i, j});
		}
	}
	
	FOR(i, 0, n + 2) FOR(j, 0, m + 2) if (s[i][j] == '.' && d2[i][j] <= dst)return 0;
	FOR(i, 1, n + 1) FOR(j, 1, m + 1) if (s[i][j] == 'X' && d2[i][j] > dst) return 0;
	return 1;	
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	s[0].assign(m + 2, '.');
	s[n + 1].assign(m + 2, '.');
	FOR(i, 1, n + 1)
	{
		cin >> s[i];
		s[i] += '.';
		reverse(ALL(s[i]));
		s[i] += '.';
		reverse(ALL(s[i]));
	}
	
	FOR(i, 0, n + 2) d[i].assign(m + 2, -1);
	queue<PII> q;
	FOR(i, 0, n + 2) FOR(j, 0, m + 2) if (s[i][j] == '.')
	{
		q.push({i, j});
		d[i][j] = 0;
	}

	while(!q.empty())
	{
		int x = q.front().X;
		int y = q.front().Y;
		q.pop();
		
		FOR(k, 0, 8)
		{
			int i = x + dx[k];
			int j = y + dy[k];
			if (!ok(i, j) || d[i][j] != -1) continue;
			d[i][j] = d[x][y] + 1;
			q.push({i, j});
		}
	}
	
	int najdali = 0;
	FOR(i, 0, n + 2) FOR(j, 0, m + 2) najdali = max(najdali, d[i][j]);
	
	int l = 0, r = najdali;
	while(r - l > 1)
	{
		int me = (l + r) >> 1;
		if (ok(me)) l = me;
		else r = me;
	}
	
	cout << l << endl;
	FOR(i, 1, n + 1)
	{
		FOR(j, 1, m + 1)
			if (s[i][j] == '.' || d[i][j] <= l) cout << '.';
			else cout << 'X';
		cout << '\n';
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}