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

const int MAX = 1 << 18;
int n;
LL ans[MAX];
LL a[MAX];

void bad()
{
	cout << "No" << endl;
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	LL x;
	LL prv = 0;
	for(int i = 2; i <= n; i += 2)
	{
		cin >> x;
		int mx = -1;
		for(int j = 1; j * j < x; ++j)
			if (x % j == 0)
				if ((j + x / j) % 2 == 0)
				{
					if ((x / j - j) / 2 > prv)
					{
						mx = j;
						a[i] = (mx + x / mx) / 2;
						a[i - 1] = (x / mx - mx) / 2;
					}
					else
						{};
				}
		
		if (mx == -1)
			bad();		
		
		prv = a[i];
		//cout << a[i - 1] << " " << a[i] << endl;
	}
	
	FOR(i, 2, n + 1)
		if (a[i] <= a[i - 1])
			bad();
	
	FOR(i, 1, n + 1)
		ans[i] = a[i] * a[i] - a[i - 1] * a[i - 1];
	
	cout << "Yes" << endl;
	FOR(i, 1, n + 1)
		cout << ans[i] << " ";
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}