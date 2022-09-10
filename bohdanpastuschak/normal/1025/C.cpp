#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int)((a).size())
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

int n;
string s;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	cin >> s;
	n = SZ(s);
	
	int ans = 0;
	bool last0 = s[0] == 'w';
	int curr = 1;
	FOR(i, 1, n)
	{
		if ((last0 && s[i] == 'w') || (!last0 && s[i] == 'b'))
		{
			ans = max(ans, curr);
			curr = 1;
		}
		else
			++curr;
		
		last0 = s[i] == 'w';
	}
	
	ans = max(ans, curr);
	
	if (s[0] != s[n - 1])
	{
		int ma_suf = 0, ma_pref = 0;
		curr = 1;
		last0 = s[0] == 'w';
		
		FOR(i, 1, n)
		{
			if ((last0 && s[i] == 'w') || (!last0 && s[i] == 'b'))
			{
				ma_suf = curr;
				break;
			}
			else
				++curr;
			
			last0 = s[i] == 'w';
		}
		
		curr = 1;
		last0 = s[n - 1] == 'w';
		RFOR(i, n - 1, 0)
		{
			if ((last0 && s[i] == 'w') || (!last0 && s[i] == 'b'))
			{
				ma_pref = curr;
				break;
			}
			else
				++curr;
			
			last0 = s[i] == 'w';
		}
		
		ans = max(ans, ma_suf + ma_pref);
	}
	
	cout << ans << endl;
	return 0;
}