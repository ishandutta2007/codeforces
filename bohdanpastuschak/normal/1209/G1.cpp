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
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
int n;
int a[N];
int last[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	int q;
	cin >> n >> q;
	
	FOR(i, 0, n)
	{
		cin >> a[i];
		last[a[i]] = i;
	}
	
	int zara = 0;
	map<int, int> mp;
	int ans = 0;
	FOR(i, 0, n)
	{
		mp[a[i]]++;
		zara = max(zara, last[a[i]]);
		if (i < zara)
			continue;
		
		int mx = 0, all = 0;
		for(auto j: mp)
		{
			mx = max(mx, j.Y);
			all += j.Y;
		}
		
		ans += all - mx;
		mp.clear();
	}
	
	
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}