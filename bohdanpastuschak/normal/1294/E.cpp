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

const int N = 1 << 18;
int n, m;

int solve(int column, vector<int>& zara)
{
	int ans = n;
	for(auto& i: zara) if (i % m != column) i = -1;
	else i /= m;
	
	map<int, int> ye;
	FOR(i, 0, n) if (zara[i] >= 0 && zara[i] < n)
		ye[(i - zara[i] + n) % n]++;
	FOR(i, 0, n)
		setmin(ans, i + n - ye[i]);
	return ans;
}

vector<int> col[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	FOR(i, 0, n) FOR(j, 0, m)
	{
		int x;
		cin >> x;
		--x;
		col[j].PB(x);
	}
	
	int ans = 0;
	FOR(i, 0, m) ans += solve(i, col[i]);
	cout << ans << endl;	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}