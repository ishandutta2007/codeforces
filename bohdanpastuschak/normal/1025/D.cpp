#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int)((a).size())
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 701;
int n;
int a[MAX];
bool can[MAX][MAX];

int gcd(int x, int y)
{
	if (!y)
		return x;
	return gcd(y, x % y);
}

bool DP[MAX][MAX][2];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
		
	FOR(i, 0, n)
		FOR(j, i + 1, n)
			can[i][j] = can[j][i] = gcd(a[i], a[j]) > 1;
	
	FOR(i, 0, n)
		can[i][n] = 1;
	
	FOR(i, 0, n)
	{
		DP[i][i][0] = DP[i][i][1] = 1;
		if (i && !can[i][i - 1])
			DP[i][i][0] = 0;
		
		if (i < n - 1 && !can[i][i + 1])
			DP[i][i][1] = 0;
	}
	
	int r;
	FOR(len, 2, n + 1)
	{
		FOR(l, 0, n - len + 1)
		{
			r = l + len - 1;
			
			FOR(k, l, r + 1)
			{
				//cout << "tut " << l << " " << r << " " << k << endl;
				if (l && !can[l - 1][k])
					continue;
				
				if (l <= k - 1 && !DP[l][k - 1][1])
					continue;
				if (r >= k + 1 && !DP[k + 1][r][0])
					continue;
					
				DP[l][r][0] = 1;
				break;
			}
			
			FOR(k, l, r + 1)
			{
				if (r + 1 < n && !can[r + 1][k])
					continue;
				
				if (l <= k - 1 && !DP[l][k - 1][1])
					continue;
					
				if (r >= k + 1 && !DP[k + 1][r][0])
					continue;
					
				DP[l][r][1] = 1;
				break;
			}
		}
	}
	
	if (DP[0][n - 1][0] || DP[0][n - 1][1])
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}