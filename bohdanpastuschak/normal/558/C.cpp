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
 
const int N = 100000 + 7;
int n;
int a[N];
int tut[N];
int cnt[N];
int vis[N];
 
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
 
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i];
		queue<PII> q;
		q.push({a[i], 0});
		
		while(!q.empty())
		{
			int v = q.front().X;
			int d = q.front().Y;
			q.pop();
			
			if (v > N || vis[v] == i + 1)
				continue;
			
			vis[v] = i + 1;
			cnt[v]++;
			tut[v] += d;
			q.push({v * 2, d + 1});
			q.push({v / 2, d + 1});
		}
	}
	
	int ans = INF;
	FOR(i, 1, N)
		if (cnt[i] == n)
			ans = min(ans, tut[i]);
			
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}