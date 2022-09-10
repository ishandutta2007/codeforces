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

const int MAX = 1 << 19;
int n;
string s[MAX];
int b[MAX];
int mn[MAX];
int vid[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
	{
		cin >> s[i];
		FOR(j, 0, SZ(s[i]))
		{
			if (s[i][j] == '(')
				b[i]++;
			else
				b[i]--;
			mn[i] = min(mn[i], b[i]);
		}
		
		if (b[i] < 0)
		{
			if (mn[i] == b[i])
				vid[-b[i]]++;
		}
	}
	
	int ans = 0;
	int cnt = 0;
	FOR(i, 0, n)
	{
		if (b[i] < 0)
			continue;
		
		if (b[i] == 0)
		{
			cnt += mn[i] >= 0;
			continue;
		}
		
		if (mn[i] < 0)
			continue;
		
		ans += vid[b[i]] > 0;
		vid[b[i]]--;
	}
	
	ans += cnt / 2;
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}