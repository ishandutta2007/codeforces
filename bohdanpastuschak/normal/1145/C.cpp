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

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int n;
	cin >> n;
	if (n == 3)
	{
		cout << 13;
		return 0;
	}
	
	if (n == 0)
	{
		cout << 15;
		return 0;
	}
	
	if (n == 1)
	{
		cout << 14;
		return 0;
		
	}
	
	if (n == 2)
	{
		cout << 12;
		return 0;
	}
	
	if (n == 4)
	{
		cout << 8;
		return 0;
	}
	
	if (n == 5)
	{
		cout << 9;
		return 0;
	}
	
	if (n == 6)
	{
		cout << 10;
		return 0;
	}
	
	if (n == 7)
	{
		cout << 11;
		return 0;
	}
	
	cout << n - 8;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}