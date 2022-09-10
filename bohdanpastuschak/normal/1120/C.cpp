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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

VI z_function (string& s) 
{
	int n = SZ(s);
	VI z(n, 0);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	
	return z;
}

const int MAX = 5000 + 7;
int n, a, b;
string s;
int dp[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> a >> b >> s;
	dp[0] = a;
	string t;
	t += s[0];
	FOR(i, 1, n)
	{
		dp[i] = dp[i -  1] + a;
		t += s[i];
		reverse(ALL(t));
		VI z = z_function(t);
		VI mx_on_suf(SZ(z));
		mx_on_suf.back() = z.back();
		RFOR(j, SZ(z) - 1, 0)
			mx_on_suf[j] = max(mx_on_suf[j + 1], z[j]);
		
		FOR(j, 1, i + 1)			
			if (mx_on_suf[i - j + 1] >= i - j + 1)
				dp[i] = min(dp[i], dp[j - 1] + b);
		
		reverse(ALL(t));
	}
	
	cout << dp[n - 1] << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}