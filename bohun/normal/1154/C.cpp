#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 105;
int a, b, c;
int day[10], ile[10];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c;
	ll ans = 0;
	day[0] = 0;
	day[1] = 1;
	day[2] = 2;
	day[3] = 0;
	day[4] = 2;
	day[5] = 1;
	day[6] = 0;
	ile[0] = 3;
	ile[1] = ile[2] = 2;
	
	for(int i = 0; 7 > i; ++i)
	{
		int w[3];
		w[0] = a;
		w[1] = b;
		w[2] = c;
		ll mini = 1000000000000;
		for(int j = 0; 3 > j; ++j)
		{
			ll e = 0;
			bool ok = 0;
			for(int g = i; 7 > g; ++g)
			{
				if(day[g] == j &&  w[j] == 0)
					{ok = 1; break;}
				++e;
				if(day[g] == j)
					w[j]--;
			}
			if(!ok)
			{
				e += (ll) 7 * (w[j] / ile[j]);
				w[j] -= ile[j] * (w[j] / ile[j]);
				//cout << i << " " << j << " " << e << " " << w[j] << endl;
				for(int g = 0; 7 > g; ++g)
				{
					if(day[g] == j && w[j] == 0)
						break;
					++e;
					if(day[g] == j)
						w[j]--;
				}
			}
			mini = min(mini, e);
		}
		ans = max(ans, mini);
	}
		cout << ans;
	
	
	
	
	return 0;
}