#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define fo(i, n) for(int i = 0; n > i; ++i)
using namespace std;

const int nax = 200005, mod = 1e9 + 7;
const int inf = 1e9;
int n, a[nax], b[nax];
multiset <int> s;
				
		
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	fo(i, n)
		cin >> a[i];
	fo(i, n)
		cin >> b[i], s.insert(b[i]);
	fo(i, n)
	{
		set <int> :: iterator it = s.lower_bound(n - a[i]);
		if(it != s.end())
		{
			cout << (a[i] + *it) % n<< " ";
		}
		else
		{
			it = s.lower_bound(0);
			cout << (a[i] + *it) % n << " ";
		}
		s.erase(it);
	}
	
	
	
	
	return 0;
}