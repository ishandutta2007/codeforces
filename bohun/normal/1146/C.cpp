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
int daj(vector <int> &a, vector <int> &b)
{
	if(ss(a) == 0 || ss(b) == 0)
		return 0;
	cout << ss(a) << " " << ss(b) << " ";
	fflush(stdout);
	for(auto it: a)
		cout << it << " ",fflush(stdout);
	for(auto it: b)
		cout << it << " ",fflush(stdout);
	cout << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}
int ans = 0;
vector <vector <int>> go, go2;
vector <int> a, b, c, d;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	int n;
	cin >> t;
	while(t--)
	{
		go.clear();
		a.clear();
		b.clear();
		c.clear();
		d.clear();
		ans = 0;
		cin >> n;
		for(int i = 1; n >= i; ++i)
		{
			if(i <= n / 2)
				a.pb(i);
			else
				b.pb(i);
		}
		ans = daj(a, b);
		go.pb(a);
		go.pb(b);
		int dd = 1;
		while(true)
		{
			dd++;
			go2.clear();
			a.clear();
			b.clear();
			for(auto it: go)
			{
				c.clear();
				d.clear();
				if(ss(it) <= 1)
					continue;
				for(int j = 0; ss(it) > j; ++j)
				{
					if(j < ss(it) / 2)
					{
						a.pb(it[j]);
						c.pb(it[j]);
					}
					else
					{
						b.pb(it[j]);
						d.pb(it[j]);
					}
				}
				if(ss(c) > 1)
				go2.pb(c);
				if(ss(d) > 1)
				go2.pb(d);
			}
			go = go2;
			ans = max(ans, daj(a, b));
			if(ss(go) == 0)
				break;
		}
		cout << -1 << " " << ans << endl;
		fflush(stdout);
	}
			
			
						
						
				
			
	return 0;
}