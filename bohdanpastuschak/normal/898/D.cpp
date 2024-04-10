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
const LL INF = 1e9;
const LL LINF = 1e18;
const int MAX = 2e5 + 47;

int n, m, k;
int a[MAX];
char banned[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m >> k;
	FOR(i, 0, n)
		cin >> a[i];

	sort(a, a + n);
	int ans = 0;

	int x = 0, y = k - 1;
	while(y < n)
	{
		while(x < n && banned[x] == 1)
			++x;

		while(y < n && banned[y] == 1)
			++y;

		if (y == n || x == n)
			break;

		if (a[y] - a[x] >= m)
		{
			++x;
			++y;
		}
		else
		{
			banned[y] = 1;
			++ans;
			++y;
		}
	}

	cout << ans << endl;
	return 0;
}