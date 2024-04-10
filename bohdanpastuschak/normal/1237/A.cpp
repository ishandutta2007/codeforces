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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 17;
int n;
int a[N];
int b[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
		
	FOR(i, 0, n)
		if (a[i] >= 0)
			b[i] = a[i] / 2;
		else
			b[i] = (a[i] - 1) / 2;
	
	int sum = 0;
	FOR(i, 0, n)
		sum += b[i];
	
	assert(sum <= 0);
	FOR(i, 0, n)
	{
		if (sum == 0) break;
		if (a[i] % 2 == 0) continue;
		sum++;
		b[i]++;
	}
	
	FOR(i, 0, n)	
		cout << b[i] << endl;
				
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}