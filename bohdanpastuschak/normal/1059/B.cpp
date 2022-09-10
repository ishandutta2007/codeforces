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
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

const int MAX = 1 << 10;
int n, m;
string s[MAX];

int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool ok(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool canBe[MAX][MAX];
bool pole[MAX][MAX];

void maluj(int x, int y)
{
	bool OK = 1;
	FOR(i, 0, 8)
		OK &= ok(x + dx[i], y + dy[i]);
	
	if (!OK)
		return;
	FOR(i, 0, 8)
		pole[x + dx[i]][y + dy[i]] = 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 0, n)
		cin >> s[i];
	
	FOR(i, 0, n)
		FOR(j, 0, m)
			canBe[i][j] = 1;
	
	FOR(i, 0, n)
		FOR(j, 0, m)
			if (s[i][j] == '.')
				FOR(k, 0, 8)
					if (ok(i + dx[k], j + dy[k]))
						canBe[i + dx[k]][j + dy[k]] = 0;
	
	FOR(i, 0, n)
		FOR(j, 0, m)
			if (canBe[i][j])
				maluj(i, j);
	
	bool OK = 1;
	FOR(i, 0, n)
		FOR(j, 0, m)
			if (pole[i][j] != (s[i][j] == '#'))
				OK = 0;
	
	if (OK)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}