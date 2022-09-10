#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
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
int n, q;
int a[N];
PII zm[N];
int suf[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
		
	cin >> q;
	FILL(zm, -1);
	FOR(i, 0, q)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int p, x;
			cin >> p >> x;
			--p; 
			zm[p] = {i, x};
		}
		else
		{
			int x;
			cin >> x;
			suf[i] = x;
		}
	}
	
	RFOR(i, q, 0)
		suf[i] = max(suf[i + 1], suf[i]);
	
	FOR(i, 0, n)
	{
		if (i)
			cout << ' ';
			
		int bulo = a[i];
		PII tut = zm[i];
		
		int from = 0;
		if (tut.X != -1)
		{
			bulo = tut.Y;
			from = tut.X;
		}
		
		bulo = max(bulo, suf[from]);		
		cout << bulo;
	}
			
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}