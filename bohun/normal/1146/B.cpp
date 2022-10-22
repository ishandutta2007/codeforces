#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 26, mod = 1e9 + 7;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string s, ans, f;
	cin >> s;
	int n = s.size();
	for(int i = 0; n > i; ++i)
	{
		f.pb(s[i]);
		if(s[i] != 'a')
			ans.pb(s[i]);
		if(ss(f) + ss(ans) == n)
		{
			if(f + ans == s)
			{
				cout << f << endl;
				return 0;
			}
			break;
		}
	}
	cout << ":(";
			
	return 0;
}