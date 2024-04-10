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
const int nax = 300005;
int n, m;
ll x[nax], p[nax];
ll war = 0;
	
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; n >= i; ++i)
		cin >> x[i];
	for(int i = 1; m >= i; ++i)
		cin >> p[i];
	war = x[2] - x[1];
	for(int i = 3; n >= i; ++i)
		war = __gcd(war, x[i] - x[i - 1]);
	for(int i = 1; m >= i; ++i)
	{
		if(war % p[i] == 0)
		{
			cout << "YES\n";
			cout << x[1] << " " << i << endl;
			return 0;
		}
	}
	cout << "NO";
	
	
				
			
	return 0;
}