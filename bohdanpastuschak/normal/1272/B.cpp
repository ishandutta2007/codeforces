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
	
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		map<char, int> mp;
		for(auto i: s) mp[i]++;
		
		int UD = min(mp['U'], mp['D']);
		int LR = min(mp['L'], mp['R']);
		
		if (UD == 0) LR = min(LR, 1);
		if (LR == 0) UD = min(UD, 1);
		
		cout << 2 * (UD + LR) << endl;
		FOR(i, 0, UD) cout << 'U';
		FOR(i, 0, LR) cout << 'R';
		FOR(i, 0, UD) cout << 'D';
		FOR(i, 0, LR) cout << 'L';
		cout << '\n';
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}