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
	
	string ans;
	int cnt = 0;
	
	ans += s[0];
	FOR(i, 1, n)
	{
		if (s[i] != s[i - 1])
		{
			ans += s[i];
			continue;
		}
		
		cnt++;
		set<char> ok;
		ok.insert('R');
		ok.insert('G');
		ok.insert('B');
				
		ok.erase(s[i - 1]);
		if (i + 1 < n)
			ok.erase(s[i + 1]);
		ans += *ok.begin();
		s[i] = *ok.begin();
	}
	
	cout << cnt << endl << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}