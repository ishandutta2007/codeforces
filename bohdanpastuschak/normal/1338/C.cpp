#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

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

LL solve1(LL n)
{
	LL curr = 1;
	while(n >= curr)
	{
		n -= curr;
		curr *= 4;
	}
	
	return n + curr;
}

LL solve2(LL n)
{
	LL curr = 2;
	while(n >= curr / 2)
	{
		n -= curr / 2;
		curr *= 4;
	}
	
	LL ans = curr;
	while(n > 0)
	{
		int chvert = n / (curr / 8);
		if (chvert == 1) ans += 2 * curr / 8;
		if (chvert == 2) ans += 3 * curr / 8;
		if (chvert == 3) ans += 1 * curr / 8;
		
		
		n %= (curr / 8);
		curr /= 4;
	}
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	FOR(i, 0, t)
	{
		LL n;
		cin >> n;
		if (n % 3 == 1) cout << solve1(n / 3) << '\n';
		if (n % 3 == 2) cout << solve2(n / 3) << '\n';
		if (n % 3 == 0) cout << (solve1(n / 3 - 1) ^ solve2(n / 3 - 1)) << '\n';
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}