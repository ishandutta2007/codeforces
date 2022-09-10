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

string one = "one";
string two = "two";

void solve()
{
	string s;
	cin >> s;
	vector<int> ans;
	vector<bool> ye(SZ(s), 1);
	FOR(i, 2, SZ(s) - 2)
		if (s[i - 2] == 't' && s[i - 1] == 'w' && s[i] == 'o'	
			&& s[i + 1] == 'n' && s[i + 2] == 'e')
				ye[i] = false, ans.PB(i);
	
	FOR(i, 1, SZ(s) - 1)
		if (ye[i - 1] && ye[i] && ye[i + 1])
		{
			if (s[i - 1] == 'o' && s[i] == 'n' && s[i + 1] == 'e')
				ans.PB(i);
			if (s[i - 1] == 't' && s[i] == 'w' && s[i + 1] == 'o')
				ans.PB(i);
		}
	
	cout << SZ(ans) << '\n';
	for(auto i: ans) cout << i + 1 << ' ';
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}