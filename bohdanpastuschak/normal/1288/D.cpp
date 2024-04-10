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
const int M = 8;
int n, m;
int a[N][M];
int mask[N];
int ye[1 << M];

bool ok(int x, bool ans = false)
{
	FILL(ye, -1);
	FOR(i, 0, n)
	{
		mask[i] = 0;
		FOR(j, 0, m) if (a[i][j] >= x) mask[i] |= 1 << j;
		ye[mask[i]] = i;
	}
	
	FOR(i, 0, 1 << m) FOR(j, 0, 1 << m)
		if (ye[i] != -1 && ye[j] != -1 && ((i | j) == (1 << m) - 1)) 
		{
			if (ans == false) return true;
			cout << ye[i] + 1 << ' ' << ye[j] + 1 << endl;
			exit(0);
		}	
	
	
	assert(ans == false);
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	FOR(i, 0, n) FOR(j, 0, m) cin >> a[i][j];
	
	int L = 0, R = INF;
	while(R - L > 1)
	{
		int Med = (L + R) >> 1;
		if (ok(Med)) L = Med;
		else R = Med;
	}
	
	debug(L)
	ok(L, true);
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}