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

const int MAX = 5000 + 7;

int n;
int a[MAX];
int DP[MAX][MAX][2][2];

inline int get(int pos, int ye, bool tut, bool tam)
{
	if (pos == 0)
	{
		if (ye || tut)
			return INF;
		else
			return 0;
	}

	if (ye < 0)
		return INF;
	
	if (pos == 1)
	{
		if (ye == 1 && tut)
		{
			int val = 0;
			if (a[2] >= a[1])
				val = a[2] - a[1] + 1;
			
			return val;
		}
		else
		{
			if (ye == 0 && !tut)
				return 0;
		}
		
		return INF;
	}
	
	if (DP[pos][ye][tut][tam] != -1)
		return DP[pos][ye][tut][tam];
	
	int res = INF;
	if (tut)
	{
		if (tam)
		{
			int val = min(a[pos - 1], a[pos - 2] - 1);
			if (val >= a[pos])
				val = val - a[pos] + 1;
			else
				val = 0;
			
			if (a[pos + 1] >= a[pos])
				val += a[pos + 1] - a[pos] + 1;
			
			res = min(res, get(pos - 2, ye - 1, 1, 0) + val);
			res = min(res, get(pos - 2, ye - 1, 1, 1) + val);
		}
		else
		{
			int val = 0;
			if (a[pos + 1] >= a[pos])
				val += a[pos + 1] - a[pos] + 1;
			if (a[pos - 1] >= a[pos])
				val += a[pos - 1] - a[pos] + 1;
			
			res = min(res, get(pos - 2, ye - 1, 0, 0) + val);
			res = min(res, get(pos - 2, ye - 1, 0, 1) + val);
		}
	}
	else
	{
		res = min(res, get(pos - 1, ye, 0, 0));
		res = min(res, get(pos - 1, ye, 0, 1));
		res = min(res, get(pos - 1, ye, 1, 0));
		res = min(res, get(pos - 1, ye, 1, 1));
	}
	
	return DP[pos][ye][tut][tam] = res;
}
 
int ans[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 1, n + 1)
		cin >> a[i];
	
	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	
	FILL(DP, -1);
	
	FOR(i, 0, MAX)
		ans[i] = INF;
	
	FOR(i, 1, n + 1)
		FOR(j, 1, (i + 1) / 2 + 1)
			FOR(l, 0, 2)
				FOR(k, 0, 2)
					ans[j] = min(ans[j], get(i, j, l, k));
	
	FOR(i, 1, (n + 1) / 2 + 1)
	{
		assert(ans[i] < INF);
		cout << ans[i] << " ";
	}
	
	cout << endl;	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}