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
const int MAX = 120000 + 47;

int n;
LL a[MAX];
map<LL, int> cnt;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];

	FOR(i, 0, n)
		cnt[a[i]]++;

	int ans = 0;

	FOR(i, 0, n)
	{
		bool ok = 0;
		FOR(j, 0, 33)
		{
			LL tut = 1LL << j;
			if (a[i] + a[i] == tut)
			{
				if (cnt[a[i]] > 1)
					ok = 1;
			}
			else
			{
				if (cnt.count(tut - a[i]))
					ok = 1;
			}
		}

		ans += !ok;
	}

	cout << ans << endl;
	return 0;
}