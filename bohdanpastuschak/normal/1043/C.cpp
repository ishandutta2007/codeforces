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
int ans[MAX];
string s;
int n;

void go(int pos, bool ok)
{
	if (pos == 0)
		return;
	
	if (s[pos] == 'a')
	{
		if (!ok)
			go(pos - 1, 0);
		else
		{
			ans[pos] = 1;
			go(pos - 1, 0);
		}
	}
	else
	{
		if (ok)
			go(pos - 1, 1);
		else
		{
			ans[pos] = 1;
			go(pos - 1, 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> s;
	n = SZ(s);
	
	if (s[n - 1] == 'a')
	{
		ans[n - 1] = 1;
		go(n - 1, 0);
	}
	else
		go(n - 1, 1);
	
	FOR(i, 0, n)
		cout << ans[i] << " ";
	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}