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
#define RFOR(i, b, a) for(LL i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (LL)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = (LL)INF * INF;

int g[10][10];
char S[5][300][300];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("In.txt" , "r" , stdin);
	int n;
	cin >> n;
	FOR(i, 0, n)
		FOR(j, 0, n)
			cin >> g[i][j];
	int w = 300;
	int k = 25;
	FOR(i, 0, 4)
		FOR(j, 0, w)
			FOR(l, 0, w)
				S[i][j][l] = '#';
	FOR(i, 0, w)
		FOR(j, 0, w)
		{
			if(i % k != 0)
			{
				if(i % k == 1 && i / k < n && j == 0)
					S[0][i][j] = i / k + 1 + '0';
				else
					S[0][i][j] = '.';
			}
		}
	FOR(i, 0, n)
	{
		S[1][k * i + 1][k * i + 1] = '.';
		S[1][k * i + 1][k * i + 2] = '.';
		S[1][k * i + 1][k * i + 3] = '.';
		FOR(j, 0, n)
			if(g[i][j])
				S[1][k * i + 1][k * j + 1] = '.';
	}
	FOR(i, 0, n)
		FOR(j, 0, w)
			S[2][j][k * i + 1] = S[3][j][k * i + 1] = '.';
	FOR(i, 0, n)
		S[2][k * i + 1][k * i + 2] = '.';
	cout << w << " " << w << " " << 4 << endl;
	FOR(i, 0, 4)
	{
		FOR(j, 0, w)
		{
			FOR(l, 0, w)
				cout << S[i][j][l];
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}