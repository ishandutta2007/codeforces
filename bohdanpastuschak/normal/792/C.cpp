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

void bad()
{
	cout << -1 << endl;
	exit(0);
}

string output(string s, bool f = 0)
{
	if (!f)
		reverse(ALL(s));
	
	int x = 0;
	while(x < SZ(s) - 1 && s[x] == '0')
		++x;
	string t;
	FOR(i, x, SZ(s))
		t += s[i];
	
	return t;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	string s;
	cin >> s;

	int cnt0 = 0, cnt1 = 0, cnt2 = 0;
	FOR(i, 0, SZ(s))
	{
		if ((s[i] - '0') % 3 == 0)
			++cnt0;
		if ((s[i] - '0') % 3 == 1)
			++cnt1;
		if ((s[i] - '0') % 3 == 2)
			++cnt2;	
	}
	
	string ANS;
	int n = SZ(s);
	if (n == 1 && !cnt0)
		bad();
	
	if (n == 2 && !cnt0 && !(cnt1 & cnt2))
		bad();
	
	int zara = cnt1 + 2 * cnt2;
	zara %= 3;
	if (zara == 0)
		ANS = output(s, 1);
	
	if (zara == 1 && cnt1)
	{
		string ans;
		RFOR(i, SZ(s), 0)
		{
			if (cnt1 && (s[i] - '0') % 3 == 1)
			{
				cnt1 = 0;
				continue;
			}
			
			ans += s[i];
		}
		
		string t = output(ans);
		if (SZ(ANS) < SZ(t))
			ANS = t;
	}
	
	if (zara == 2 && cnt2)
	{
		string ans;
		RFOR(i, SZ(s), 0)
		{
			if (cnt2 && (s[i] - '0') % 3 == 2)
			{
				cnt2 = 0;
				continue;
			}
			
			ans += s[i];
		}
		
		string t = output(ans);
		if (SZ(ANS) < SZ(t))
			ANS = t;
	
	}
	
	cnt0 = 0, cnt1 = 0, cnt2 = 0;
	FOR(i, 0, SZ(s))
	{
		if ((s[i] - '0') % 3 == 0)
			++cnt0;
		if ((s[i] - '0') % 3 == 1)
			++cnt1;
		if ((s[i] - '0') % 3 == 2)
			++cnt2;	
	}
	
	if (zara == 1 && cnt2 >= 2)
	{
		string ans;
		cnt2 = 2;
		RFOR(i, SZ(s), 0)
		{
			if (cnt2 && (s[i] - '0') % 3 == 2)
			{
				cnt2--;
				continue;
			}
			
			ans += s[i];
		}
		string t = output(ans);
			if (SZ(ANS) < SZ(t))
				ANS = t;
		
	}
	
	if (zara == 2 && cnt1 >= 2)
	{
		cnt1 = 2;
		string ans;
		RFOR(i, SZ(s), 0)
		{
			if (cnt1 && (s[i] - '0') % 3 == 1)
			{
				cnt1--;
				continue;
			}
			
			ans += s[i];
		}
		string t = output(ans);
		if (SZ(ANS) < SZ(t))
			ANS = t;
	
	}

	cout << ANS << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}