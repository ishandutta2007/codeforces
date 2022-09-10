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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

int n, m, q;
string a, b;
bool ok[1 << 10];
int cnt[1 << 10];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> m >> q >> a >> b;
	FOR(i, 0, n - m + 1)
	{
		ok[i] = 1;
		FOR(j, 0, m)
		{
			if (a[i + j] != b[j])
			{
				ok[i] = 0;
				break;
			}
		}
	}
	
	cnt[0] = ok[0];
	FOR(i, 1, n)
		cnt[i] = cnt[i - 1] + ok[i];
	
	int l, r;
	while(q--)
	{
		cin >> l >> r;
		--l, --r;		
		int ans = 0;
		if (r - m + 1 >= l)
		{
			ans = cnt[r - m + 1];
			if (l)
				ans -= cnt[l - 1];
		}
		
		cout << ans << endl;
	}
	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}