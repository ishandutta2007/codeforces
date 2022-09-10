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
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

const int MAX = 1 << 20;
int a[MAX];

void f(int n, int s, int mn)
{
	if (n == 1)
	{
		a[s] = mn;
		return;
	}
	
	if (n == 2)
	{
		a[s] = mn;
		a[s + 1] = mn * 2;
		return;
	}
	
	if (n == 3)
	{
		a[s] = mn;
		a[s + 1] = mn;
		a[s + 2] = mn *3;
		return;
	}
	
	if (n & 1)
	{
		FOR(i, 0, n / 2 + 1)
			a[i + s] = mn;
		f(n >> 1, s + n / 2 + 1, mn * 2);
	}
	else
	{
		FOR(i, 0, n >> 1)
			a[i + s] = mn;
		
		f(n >> 1, s + (n >> 1), mn * 2);
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	int n;
	cin >> n;
	f(n, 0, 1);
	FOR(i, 0, n)
		cout << a[i] << " ";
	cout << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}