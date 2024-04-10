#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 200005;
int n, t[nax];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	int zero =0, ones = 0;
	for(int i = 1; n >= i; ++i)
	{
		cin >> t[i];
		if(t[i] == 0)
			zero ++;
		if(t[i] == 1)
			ones ++;
	}
	int a =0, b= 0;
	for(int i = 1; n >= i; ++i)
	{
		if(t[i] == 0)
			a++;
		else
			b++;
		if(a == zero or b == ones)
		{
			cout << i;
			return 0;
		}
	}
	
	
	return 0;
}