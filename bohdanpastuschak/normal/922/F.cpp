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
#define nedl endl

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;

const int MAX = 1 << 19;
int p[MAX];
VI d[MAX];

int tau(int n)
{
	int res = 1;
	while(n > 1)
	{
		int q = p[n];
		int cnt = 0;
		while(n % q == 0)
			cnt++, n /= q;
		res *= cnt + 1;
	}
	
	return res;
}

void bad()
{
	cout << "No" << endl;
	exit(0);
}

bool ok(VI& a, int k)
{
	int res = 0;
	FOR(i, 0, SZ(a))
		FOR(j, i + 1, SZ(a))
			res += a[j] % a[i] == 0;
	
	return res == k;
}

int cnt[MAX];
bool deleted[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	FOR(i, 2, MAX)
		p[i] = i;
	
	FOR(i, 2, MAX)
		if (p[i] == i)
			for(LL j = i * (LL) i; j < MAX; j += i)
				if (p[j] == j)
					p[j] = i;
		
	int n, k;
	cin >> n >> k;
	
	int total = 0;
	FOR(i, 1, n + 1)
	{
		total += tau(i) - 1;
		if (total >= k)
		{
			n = i;
			break;
		}
	}
		
	if (total < k)
		bad();
	
	cout << "Yes" << endl;
	int lyshni = total - k;

	FOR(i, 1, n + 1)
		for(int j = i + i; j <= n; j += i)
			cnt[j]++, cnt[i]++, d[j].PB(i);
	
	while(lyshni)
	{
		int mx = -1;
		RFOR(i, n + 1, 1)
		{
			if (deleted[i])
				continue;
			
			if (cnt[i] <= lyshni && (mx == -1 || cnt[i] > cnt[mx]))
				mx = i;
		}
		
		int i = mx;
		lyshni -= cnt[i];
	//	cout << i << endl;
		deleted[i] = 1;
		for(int j = i + i; j <= n; j += i)
			cnt[j]--;
		
		for(auto j: d[i])
			cnt[j]--;		
	}
		
	VI ans;
	FOR(i, 1, n + 1)
		if (!deleted[i])
			ans.PB(i);
	cout << SZ(ans) << endl;
	for(auto i: ans)
		cout << i << ' ';
	cout << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}