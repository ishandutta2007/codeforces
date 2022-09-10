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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void bad()
{
	cout << "No" << endl;
	exit(0);
}

void ok()
{
	cout << "Yes" << endl;
	exit(0);
}

bool check(string& s)
{
	int n = SZ(s);
	int bal = 0, mn = 0;
	
	FOR(i, 0, n)
	{
		if (s[i] == '(')
			++bal;
		else
			--bal;
		mn = min(mn, bal);
	}
	
	return mn == 0;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	int n;
	string s;
	cin >> n >> s;
	
	int bal = 0, mn = 0;
	FOR(i, 0, n)
	{
		if (s[i] == '(')
			++bal;
		else
			--bal;
		mn = min(mn, bal);
	}
	
	if (bal != 0)
		bad();
	
	if (mn == 0)
		ok();
		
	if (mn != -1)
		bad();
	
	string ans;
	bool bulo = 0;
	FOR(i, 0, n)	
		if (s[i] == '(')
		{
			ans += s[i];
		}
		else
		{
			if (!bulo)
			{
				bulo = 1;
				continue;
			}
			
			ans += s[i];
		}
		
	ans += ')';
	if (check(ans))
		ok();
	else
		bad();
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}