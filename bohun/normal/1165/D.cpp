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
const int nax = 200005, mod = 998244353;
const ll inf = 1e18;

int t;
int n;
int d[nax];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; n >= i; ++i)
			cin >> d[i];
		bool ok = 1;
		sort(d + 1, d + n + 1);
		ll liczba = (ll) d[1] * d[n];
		for(int i = 1; n >= i; ++i)
		{
			if(liczba % d[i] != 0)
				ok = 0;
			bool jest = 0;
			for(int j = 1; n >= j; ++j)
			{
				if((ll) d[i] * d[j] == liczba)
					jest = 1;
			}
			if(!jest)
				ok = 0;
		}
		if(!ok)
		{
			cout << -1 << endl;
			continue;
		}
		vector <int> div;
		ll N = liczba;
		for(int i = 2; (ll) i * i <= liczba; ++i)
		{
			if(liczba % i == 0)
			{
				while(N % i == 0)
					N /= i;
				div.pb(i);
				if((ll) i * i != liczba)
					div.pb(liczba / i);
			}
		}
		sort(div.begin(), div.end());
		if(ss(div) != n)
			ok = 0;
		if(!ok)
		{
			cout << -1 << endl;
			continue;
		}
		for(int j = 0; n > j; ++j)
			if(div[j] != d[j + 1])
				ok = 0;
		if(!ok)
		{
			cout << -1 << endl;
			continue;
		}
		cout << liczba << endl;
	}
		
		
		
	
    return 0;
}