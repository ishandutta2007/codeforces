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

int n;
int a[20];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
	
	bool ok = 0;
	int N = 360;
	FOR(mask, 0, 1 << n)
	{
		int sum = 0;
		FOR(i, 0, n)
			if (mask & (1 << i))
				sum += a[i];
			else
				sum -= a[i];
		
		sum = ((sum % N) + N) % N;
		ok |= sum == 0;
	}
	
	if (ok)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}