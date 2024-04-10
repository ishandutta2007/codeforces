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
const LL INF = 1e9;
const LL LINF = 1e18;
const int MAX = 2e5 + 47;

bool ok(int n)
{
	for(int i = 2; i * i <= n; ++i)
	{
		if (n % i)
			continue;

		while(n % i == 0)
			n /= i;

		return n == 1;
	}

	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int n;
	cin >> n;
	VI a;
	FOR(i, 2, n + 1)
		if (ok(i))
			a.PB(i);

	cout << SZ(a) << endl;
	FOR(i, 0, SZ(a))
		cout << a[i] << " " ;
	cout << endl;


	return 0;
}