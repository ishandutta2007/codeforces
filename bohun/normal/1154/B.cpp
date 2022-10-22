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
int n, t[nax];
bool fun(int r, int first)
{
	for(int i = 2; n >= i; ++i)
	{
		if(t[i] + r != first && t[i] != first && t[i] - r != first)
			return 0;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; n >= i; ++i)
	{
		cin >> t[i];
	}
	for(int d = 0; 100 >= d; ++d)
	{
		if(fun(d, t[1] + d) || fun(d, t[1]) || fun(d, t[1] - d))
		{
			cout << d;
			return 0;
		}
	}
	cout << -1;
	
	
	
	return 0;
}