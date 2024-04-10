#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
	ll n, k;
	cin >> n >> k;
	ll ncpy = n;
	ll f10 = 0;
	ll f5 = 0;
	ll f2 = 0;
	while(ncpy%10 == 0)
	{
		ncpy /= 10; ++f10;
	}
	while(ncpy%5 == 0)
	{
		ncpy /= 5; ++f5;
	}
	while(ncpy%2 == 0)
	{
		ncpy /= 2; ++f2;
	}
	//cerr << f10 << " " << f5 << ":" << k << endl;
	if(f10 >= k)
		cout << n << endl;
	else {
		//cerr << "OTHER" << endl;
	ll val = n;
	ll tenfactors = f10;
	while(tenfactors < k) {
		if(f5 > 0) {
			val *= 2; -- f5;
			++tenfactors;
		}
		else if(f2 > 0) {
			val *= 5; -- f2;
			++tenfactors;
		}
		else
		{
			val *= 10;
			++tenfactors;
		}
	}
	cout << val << endl;
	}


	
	
	
	return 0;
}