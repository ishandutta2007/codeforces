#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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

int n, s, k;
const int MAX = 1 << 11;
string S;
int cnt[50];
VI g[MAX];
int dp[50][MAX];

int get(int pos, int she)
{
	if (she + cnt[pos] >= k)
		return 0;
	
	if (dp[pos][she] != -1)
		return dp[pos][she];
	
	int res = INF;
	for(auto i: g[pos])
		res = min(res, abs(i - pos) + get(i, she + cnt[pos]));
	
	return dp[pos][she] = res;
}

void build()
{
	FOR(i, 0, n)
		FOR(j, 0, n)
			if (S[i] != S[j] && cnt[i] < cnt[j])
				g[i].PB(j);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n >> s >> k;
	--s;
	FOR(i, 0, n)
		cin >> cnt[i];
	cin >> S;
	build();
	FILL(dp, -1);
	int ans = INF;
	FOR(i, 0, n)
		ans = min(ans, abs(i - s) + get(i, 0));
	if (ans == INF)
		ans = -1;
	cout << ans << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}