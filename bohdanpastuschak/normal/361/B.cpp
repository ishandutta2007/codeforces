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
	
	int n, k;
	cin >> n >> k;
	if (k == n)
	{
		cout << -1 << endl;
		return 0;
	}
	
	VI a(n);
	FOR(i, 0, n)
		a[i] = i + 1;
	
	k = n - 1 - k;
	for(int i = n - 1; i >= 1; i -= 2)
	{
		if (k > 1)
			swap(a[i], a[i - 1]), k -= 2;
	}
	
	if (k)
		swap(a[0], a[1]);
	
	for(auto i: a)
		cout << i << ' ';
	cout << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}