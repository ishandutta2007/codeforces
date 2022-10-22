#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
bool put(ll a, ll b)
{
	cout << "? " << a << " " << b << endl;
	cout.flush();
	string x;
	cin >> x;
	if(x[0] == 'x')
		return 1;
	else
		return 0;
}
void ans(int x)
{
	cout << "! " << x << endl;
	cout.flush();
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string s;
	while(true)
	{
		cin >> s;
		if(s[0] == 'e')
			return 0;
		ll x = 0;
		ll y = 1;
		while(put(x,y) == 0)
		{
			if(!x)
				x = 1;
			else
				x *= 2;
			y *= 2;
		}
		ll lewo = x + 1;
		ll prawo = y;
		while(prawo > lewo)
		{
			ll mid = (lewo + prawo) / 2;
			if(put(x, mid) == 1)
				prawo = mid;
			else
				lewo = mid + 1;
		}
		ans(lewo);
	}
		
	return 0;	
}