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

const int N = 1 << 17;
const int M = 11;
int n;
int a[N];
int cnt[M][N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
	
	FOR(j, 0, M)
	{
		cnt[j][0] = a[0] == j;
		FOR(i, 1, n)	
			cnt[j][i] = cnt[j][i - 1] + (a[i] == j);
	}
	
	int ans = 0;
	RFOR(i, n, 0)
	{
		VI tut;
		FOR(j, 0, M)
			if (cnt[j][i])
				tut.PB(cnt[j][i]);
		sort(ALL(tut));
		if (SZ(tut) == 1)
		{
			ans = i;
			break;
		}
		
		if (tut[0] == 1 && tut[1] == tut.back())
		{
			ans = i;
			break;
		}
		
		if (tut[0] == tut.back() - 1 && tut[0] == tut[SZ(tut) - 2])
		{
			ans = i;
			break;
		}
	}
	
	cout << ans + 1 << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}