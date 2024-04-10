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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

const int mod = 998244353;

inline int add(int x, int y)
{
	if (x + y >= mod)
		return x + y - mod;
	return x + y;
}

int n, k;
int DP[1001][2001][4];

int solve(int pos, int cnt, int mask)
{
	if (cnt < 0)
		return 0;
	
	if (pos == n - 1)
		return cnt == 0;
	
	mask = min(mask, 3 - mask);
	if (DP[pos][cnt][mask] != -1)
		return DP[pos][cnt][mask];
	
	int res = 0;
	
	if (mask == 0)
	{
		res = add(res, solve(pos + 1, cnt, 0));
		FOR(i, 1, 4)
			res = add(res, solve(pos + 1, cnt - 1, i));
	}
	else
	{
		if (mask == 3)
		{
			FOR(i, 0, 3)
				res = add(res, solve(pos + 1, cnt - 1, i));
			
			res = add(res, solve(pos + 1, cnt, 3));
		}
		else
		{
			if (mask == 1)
			{
				res = add(res, solve(pos + 1, cnt, 0));
				res = add(res, solve(pos + 1, cnt, 1));
				res = add(res, solve(pos + 1, cnt - 2, 2));
				res = add(res, solve(pos + 1, cnt, 3));					
			}
			else
			{
				res = add(res, solve(pos + 1, cnt, 0));
				res = add(res, solve(pos + 1, cnt, 1));
				res = add(res, solve(pos + 1, cnt - 2, 2));
				res = add(res, solve(pos + 1, cnt, 3));		
			}
		}			
	}
	
	return DP[pos][cnt][mask] = res;		
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> k;
	FILL(DP, -1);
	
	int ans = 0;
	ans = add(ans, solve(0, k - 1, 0));
	ans = add(ans, solve(0, k - 1, 3));
	ans = add(ans, solve(0, k - 2, 1));
	ans = add(ans, solve(0, k - 2, 2));
	
	cout << ans << endl;	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}