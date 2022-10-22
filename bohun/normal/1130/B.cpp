#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int t[200005];
vector < int > v[100005];
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 1; 2 * n >= i; ++i)
		{
			cin >> t[i];
			v[t[i]].push_back(i);
		}
	int a = 1;
	int b = 1;
	ll ans = 0;
	for(int i = 1; n >= i; ++i)
	{
		if( abs (a - v[i][0] ) + abs (b - v[i][1]) > abs(a - v[i][1]) + abs(b - v[i][0]))
		{
			ans += abs(a - v[i][1]) + abs(b - v[i][0]);
			a = v[i][1];
			b = v[i][0];
		}
		else
		{
			ans += abs(a - v[i][0]) + abs(b - v[i][1]);
			a = v[i][0];
			b = v[i][1];
		}
	}
	cout << ans;
	
	return 0;	
}