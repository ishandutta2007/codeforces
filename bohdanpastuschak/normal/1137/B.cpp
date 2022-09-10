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

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	string s, t;
	cin >> s >> t;
	
	int n = SZ(s);
	int os = 0, zs = 0;
	int ot = 0, zt = 0;
		
	FOR(i, 0, SZ(s))
	{
		os += s[i] == '1';
		zs += s[i] == '0';
	}
	
	FOR(i, 0, SZ(t))
	{
		ot += t[i] == '1';
		zt += t[i] == '0';
	}
	
	VI p = prefix_function(t);
	int len = p.back();
	int per = SZ(t) - len;
	
	string ans = t;
	if (ot > os || zt > zs)
	{
		cout << s;
		return 0;
	}
	
	int ye0 = zt, ye1 = ot;
	while(SZ(ans) + per <= SZ(s))
	{
		int here0 = 0, here1 = 0;
		FOR(i, len, SZ(t))
		{
			here0 += t[i] == '0';
			here1 += t[i] == '1';
		}
		
		if (ye0 + here0 > zs || ye1 + here1 > os)
			break;
		
		FOR(i, len, SZ(t))
			ans += t[i];
		ye0 += here0;
		ye1 += here1;
	}
	
	FOR(i, 0, zs - ye0)
		ans += '0';
	FOR(i, 0, os - ye1)
		ans += '1';
	
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}