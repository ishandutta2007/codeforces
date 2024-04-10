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
PII s[N << 1];

int ok(int x)
{
	FOR(i, 0, n)
	{
		s[i << 1] = MP(a[i] - x, 1);
		s[(i << 1) | 1] = MP(a[i] + x + 1, -1);
	}
	
	sort(s, s + n + n);
	int bal = 0;
	
	FOR(i, 0, n + n)
	{
		bal += s[i].Y;
		if (bal > k)	
			return s[i].X;
	}
	
	return -INF;	
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		FOR(i, 0, n)
			cin >> a[i];
		
		int L = 0, R = INF, M;
		while(R - L > 1)
		{
			M = (L + R) >> 1;
			if (ok(M) > -INF)
				R = M;
			else
				L = M;
		}
		
		if (ok(L) > -INF)
			M = L;
		else
			M = R;
		
		//debug(M);
		cout << ok(M) << endl;
	}

	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}