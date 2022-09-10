#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 19;
int n;
int a[N];
int b[N];

inline int get_on_range(int from, int to)
{
	if (from > to) return 0;
	auto it1 = lower_bound(b, b + n, from) - b;
	auto it2 = upper_bound(b, b + n, to) - b;
	return it2 - it1;
}

bool solve(int k)
{
	sort(b, b + n);
	
//	FOR(i, 0, n) cout << b[i] << ' ';
//	cout << endl;
	
	LL ans = 0;
	int cnt_now = 1;
	FOR(i, 1, n) if (b[i] == b[i - 1]) cnt_now++;
	else
	{
		int hto = b[i - 1];
		if ((2 * hto) & (1 << k)) ans += cnt_now * (LL) (cnt_now - 1) / 2;
		
		if (hto < (1 << k))
		{
			int from = max(hto + 1, (1 << k) - hto);
			int to = (1 << (k + 1)) - hto - 1;
			ans += get_on_range(from, to) * (LL) cnt_now;
		}
		else
		{
			int from = max(hto + 1, 3 * (1 << k) - hto);
			int to = INF;
			
			ans += get_on_range(from, to) * (LL) cnt_now;
		}
		
		cnt_now = 1;
	}	
	
	int hto = b[n - 1];
	if ((2 * hto) & (1 << k)) ans += cnt_now * (LL) (cnt_now - 1) / 2;
		
	if (hto < (1 << k))
	{
		int from = max(hto + 1, (1 << k) - hto);
		int to = (1 << (k + 1)) - hto - 1;
		ans += get_on_range(from, to) * (LL) cnt_now;
	}
	else
	{
		int from = max(hto + 1, 3 * (1 << k) - hto);
			int to = INF;
		
		ans += get_on_range(from, to) * (LL) cnt_now;
	}
	
	return ans & 1;
}

int main()
{	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	
	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	
	int ans = 0;
	//int k = 2;
	FOR(k, 0, 25)
	{
		FOR(i, 0, n)
			b[i] = (a[i] & ((1 << (k + 1)) - 1));
		if (solve(k)) ans |= 1 << k;
	}
	
	cout << ans << endl;	
	
	//cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}