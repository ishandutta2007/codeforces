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

const int N = 1 << 20;
int n, x;
int a[N];
int right_most[N];
int left_most[N];
int right_pref[N];
int left_suf[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
		
	cin >> n >> x;
	FILL(left_most, -1);
	FILL(right_most, -1);
	
	FOR(i, 0, n)
	{
		cin >> a[i];
		if (left_most[a[i]] == -1)
			left_most[a[i]] = i;
		right_most[a[i]] = i;
	}
	
	FOR(i, 1, x + 1)
	{
		right_pref[i] = right_pref[i - 1];
		if (right_most[i] != -1)
			right_pref[i] = max(right_pref[i], right_most[i]);
	}
	
	left_suf[x + 1] = n;
	RFOR(i, x + 1, 1)
	{
		left_suf[i] = left_suf[i + 1];
		if (left_most[i] != -1)
			left_suf[i] = min(left_suf[i], left_most[i]);
	}
	
	int last_good = x;
	FOR(i, 1, x + 1)
	{
		if (left_most[i] == -1)
			continue;
		
		if (left_most[i] < right_pref[i - 1])
		{
			last_good = i;
			break;
		}
	}
	
	int first_good = 1;
	RFOR(i, x + 1, 1)
	{
		if (right_most[i] == -1)
			continue;
		
		if (right_most[i] > left_suf[i + 1])
		{
			first_good = i;
			break;
		}		
	}
	
	LL ans = 0;
	
	FOR(l, 1, last_good + 1)
	{
		int last = right_pref[l - 1];
		
		int L = max(first_good, l), R = x, M;
		while(R - L > 1)
		{
			M = (L + R) >> 1;
			if (left_suf[M + 1] < last)
				L = M;
			else
				R = M;
		}		
		
		M = L;
		if (left_suf[M + 1] < last)
			++M;
			
		assert(left_suf[M + 1] >= last);
		ans += x - M + 1;
	}
	
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}