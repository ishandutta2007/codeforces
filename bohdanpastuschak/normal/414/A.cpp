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

void bad()
{
	cout << - 1 << endl;
	exit(0);
}

char banned[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int n, k;
	cin >> n >> k;

	if (n == 1 && k)
		bad();

	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	int pairs = n / 2;
	if (k < pairs)
		bad();

	cout << k - pairs + 1 << " " << 2*(k - pairs + 1);
	FOR(i, 2 * k + 2, 2* k + n)
		cout << " " << i;
	cout << endl;
	return 0;
}