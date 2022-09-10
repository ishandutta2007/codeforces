#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	string s;
	cin >> s;
	while(s.size() > 0 && s.back() == 'o')
		s.pop_back();
	reverse(ALL(s));
	while(s.size() > 0 && s.back() == 'o')
		s.pop_back();
	reverse(ALL(s));
	int n = SZ(s);
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	
	VI v, o;
	int now = 1;
	FOR(i, 1, n)
		if (s[i] == s[i - 1])
			now++;
		else
		{
			if (s[i - 1] == 'v')
				v.PB(now - 1);
			if (s[i - 1] == 'o')
				o.PB(now);
				
			now = 1;
		}
	
	v.PB(now - 1);
	
	int all = 0;
	for(auto i: v)
		all += i;
	
	int vje = 0;
	LL ans = 0;
	
	FOR(i, 0, SZ(o))
	{
		vje += v[i];
		ans += o[i] * (LL) vje * (all - vje);
	}
		
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}