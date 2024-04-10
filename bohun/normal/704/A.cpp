#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define up(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int nax = 300005;
const ll inf = 1e18;
set <int> s;
int czas = 1;
vector <int> v[nax];
int n, q;
int t, a;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> q;
	while(q--)
	{
		cin >> t >> a;
		if(t == 1)
		{
			v[a].pb(czas);
			s.insert(czas);
			czas++;
		}
		else if(t == 2)
		{
			for(auto it: v[a])
			{
				if(s.find(it) != s.end())
					s.erase(it);
			}
			v[a].clear();
		}
		else if(t == 3)
		{
			while(ss(s) && *s.begin() <= a)
				s.erase(s.begin());
		}
		cout << ss(s) << endl;
	}
				
		
						
							
					
					
						
							
						
		
		
    return 0;
}