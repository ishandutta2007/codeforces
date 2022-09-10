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

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		vector<string> s(n);
		FOR(i, 0, n) cin >> s[i];
		int ans = 0;
		vector<string> t = s;
		FOR(i, 0, n)
		{
			bool ok = 1;
			FOR(j, 0, n) if (i != j) ok &= t[i] != t[j];
			if (ok) continue;
			ans++;
			
			bool fnd = 0;
			FOR(d, 0, 4) FOR(nx, 0, 10)
			{
				if (fnd) break;
				string bude = t[i];
				bude[d] = (char)('0' + nx);
				ok = 1;
				FOR(j, 0, n) if (i != j) ok &= bude != t[j];
				if (!ok) continue;
				fnd = 1;
				t[i] = bude;
			}
			
			assert(fnd);
		}
		
		cout << ans << endl;
		FOR(i, 0, n) cout << t[i] << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}