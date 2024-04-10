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
int n, k;
int a[N];
vector<PII> b[N];

void go(int x, int id)
{
	for(int i = 2; i * i <= x; ++i)
		if (x % i == 0)
		{
			int cnt = 0;
			while(x % i == 0) x /= i, cnt++;
			cnt %= k;
			if (cnt)
				b[id].PB({i, cnt});
		}
		
	if (x > 1)
		b[id].PB({x, 1});
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
		
	cin >> n >> k;
	FOR(i, 0, n)
	{
		cin >> a[i];
		go(a[i], i);
	}
	
	LL ans = 0;
	map<vector<PII>, int> mp;
	FOR(i, 0, n)
		mp[b[i]]++;
		
	FOR(i, 0, n)
	{
		vector<PII> tut = b[i];
		vector<PII> treba;
		for(auto x: tut)
		{
			int bude = k - x.Y;
			if (bude)
				treba.PB({x.X, bude});
		}
		
		if (tut != treba)
			ans += mp[treba];
	}
	
	ans >>= 1;
	for(auto i: mp)
	{
		bool tut = 1;
		for(auto j: i.X)
			tut &= (j.Y * 2 == k);
			
		if (tut)
			ans += i.Y * (LL) (i.Y - 1) / 2;
	}
	
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}