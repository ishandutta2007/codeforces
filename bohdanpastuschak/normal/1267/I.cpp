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
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX = 220;

char ans[MAX][MAX];

bool better(int x, int y)
{
	x++;
	y++;
	if(ans[x][y] != '?')
		return ans[x][y] == '>';
	cout << "? " << x << ' ' << y << endl;
	fflush(stdout);
	char c;
	cin >> c;
	ans[x][y] = c;
	return c == '>';
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		FOR(i, 1, 2 * n + 1)
			FOR(j, 1, 2 * n + 1)
				ans[i][j] = '?';
		int a1 = 0, a2 = 1, b1 = 2, b2 = 3;
		if(better(a2, a1))
			swap(a1, a2);
		if(better(b2, b1))
			swap(b1, b2);
		FOR(i, 4, 2 * n)
		{
			bool aSynok = better(b2, a2);
			if(aSynok)
			{
				a2 = i;
				if(better(a2, a1))
					swap(a1, a2);
			}
			else
			{
				b2 = i;
				if(better(b2, b1))
					swap(b1, b2);
			}
		}
		vector<int> top3 = {a1, b1};
		if(better(a2, b2))
			top3.PB(a2);
		else
			top3.PB(b2);
		FOR(i, 0, 2 * n)
		{
			bool ok = true;
			FOR(j, 0, 3)
				ok &= top3[j] != i;
			if(!ok)
				continue;
			FOR(j, 0, 2 * n)
				if(j != i)
					better(i, j);
		}
		cout << "!" << endl;
		fflush(stdout);
	}	
	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}