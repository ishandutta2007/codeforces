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
const LL INF = 1e9;
const LL LINF = INF * INF;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int n;
	cin >> n;
	string s;
	cin >> s;
	
	string ans(n, '1');
	int cnt = INF;
	
	FOR(r, 0, 3)
		FOR(g, 0, 3)
			FOR(b, 0, 3)
			{
				if (r == g || r == b || g == b)
					continue;
				
				int dst = 0;
				FOR(i, 0, n)
				{
					if (s[i] == 'R' && (i % 3 != r))
						++dst;
					if (s[i] == 'G' && (i % 3 != g))
						++dst;
					if (s[i] == 'B' && (i % 3 != b))
						++dst;				
				}
				
				if (dst < cnt)
				{
					cnt = dst;
					FOR(i, 0, n)
						if (i % 3 == r)
							ans[i] = 'R';
						else
							if (i % 3 == g)
								ans[i] = 'G';
							else
								ans[i] = 'B';
				}
				
			}
	
	
	cout << cnt << endl << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}