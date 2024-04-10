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

bool check(string& x, string& s, string& t)
{
	FOR(i, 0, SZ(x) - 1)
		if (x[i] == s[0] && x[i + 1] == s[1])
			return 0;
	
	FOR(i, 0, SZ(x) - 1)
		if (x[i] == t[0] && x[i + 1] == t[1])
			return 0;
	
	return 1;
}

void solve(int n, string s, string t)
{
	if (s[0] == t[1] && s[1] == t[0] && s[0] != s[1])//ab ba
	{
		cout << "YES" << endl;
		char x = 'a';
		while(x == s[0] || x == s[1])
			x++;
		
		FOR(i, 0, n)
			cout << s[0];
		FOR(i, 0, n)
			cout << x;
		FOR(i, 0, n)
			cout << s[1];
		cout << endl;
		return;	
	}
	
	if (s[0] == t[0] && s[0] != s[1] && s[0] != t[1])//ab ac
	{
		cout << "YES" << endl;
		char x = 'a';
		while(x == s[0])
			x++;
		char y = 'a';
		while(y == x || y == s[0])
			y++;
		
		FOR(i, 0, n)
			cout << x;
		FOR(i, 0, n)
			cout << y;
		FOR(i, 0, n)
			cout << s[0];
		cout << endl;
		
		return;
	}
	

	string res = "abc";
	do
	{
		string kek(3 * n, 'a');
		FOR(i, 0, n)
			FOR(j, 0, 3)
				kek[3 * i + j] = res[j];
		
		if (check(kek, s, t))
		{
			cout << "YES" << endl;
			cout << kek << endl;
			return;
		}
	}while(next_permutation(ALL(res)));
	
	
	char z = s[1];
	char x = 'a';
	while(x == z)
		x++;
	char y = 'a';
	while(y == z || y == x)
		y++;
		
	cout << "YES" << endl;
	FOR(i, 0, n)
		cout << z;
	FOR(i, 0, n)
		cout << x;
	FOR(i, 0, n)
		cout << y;
	cout << endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	int n;
	string s, t;
	cin >> n >> s >> t;
	solve(n, s, t);
	
	return 0;
	vector<string> all;
	for(char x = 'a'; x <= 'c'; ++x)
		for(char y = 'a'; y <= 'c'; ++y)
		{
			string r;
			r += x;
			r += y;
			all.PB(r);
		}
	
	FOR(i, 0, SZ(all))
		FOR(j, 0, SZ(all))
			solve(4, all[i], all[j]);			
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}