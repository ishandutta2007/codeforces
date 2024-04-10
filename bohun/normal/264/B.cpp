#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)
using namespace std;


const int nax = 100005, mod = 998244353, pot = 17;
int t[nax], n;
int best[nax];
int sito[nax];
int res = 1;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	for(int i = 2; nax > i; ++i)
	{
		if(sito[i] == 0)
		{
			for(int j = i; nax > j; j += i)
				sito[j] = i;
		}
	}
	
	cin >> n;
	for(int i = 1; n >= i; ++i)
	{
		cin >> t[i];
		int ans = 0;
		int x = t[i];
		while(x != 1)
		{
			ans = max(ans, best[sito[x]]);
			x /= sito[x];
		}
		x = t[i];
		while(x != 1)
		{
			best[sito[x]] = max(best[sito[x]], ans + 1);
			x /= sito[x];
		}
		res = max(res, ans + 1);	
	}
	cout << res;

    return 0;
}