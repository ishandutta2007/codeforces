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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
int n, k;
int a[N];

bool ok(int x)
{
	LL treba = 0;
	FOR(i, n >> 1, n)
		if (a[i] < x)
			treba += x - a[i];
	
	return treba <= k;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> k;
	FOR(i, 0, n)
		cin >> a[i];
	sort(a, a + n);
	
	LL L = 0, R = 2 * INF, M;
	while(R - L > 1)
	{
		M = (L + R) / 2;
		if (ok(M))
			L = M;
		else
			R = M;
	}
	
	assert(ok(L));
	assert(!ok(L + 1));	
	
	cout << L << endl;	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}