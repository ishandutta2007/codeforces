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

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = 1e18;
const int MAX = 2e5 + 47;

int s[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	FOR(i, 0, MAX)
		s[i] = i;

	FOR(i, 2, MAX)
		if (s[i] == i)
			for(LL j = 1LL * i * i; j < MAX; j += i)
				if (s[j] == j)
					s[j] = i;

	int n, k;
	cin >> n >> k;
	VI ans;
	while(n > 1 && SZ(ans) < k)
	{
		int t = s[n];
		n /= t;
		ans.PB(t);
	}

	ans[0] *= n;
	if (SZ(ans) < k)
		cout << -1 << endl;
	else
		FOR(i, 0, SZ(ans))
			cout << ans[i] << " ";

	return 0;
}