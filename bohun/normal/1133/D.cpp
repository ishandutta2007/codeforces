#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n;
int ans = 0;
map < pair < int, int > ,int > m;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	int a[200005], b[200005];
	for(int i = 1; n >= i ;++i)
	{
		cin >> a[i];
	}
	for(int i = 1; n >= i; ++i)
		cin >> b[i];
	for(int i = 1;  n >= i; ++i)
	{
		if(a[i] == 0)
		{
			ans += (b[i] == 0);
			continue;
		}
		int g =__gcd(a[i], b[i]);
		a[i] /= g;
		b[i] /= g;
		if(a[i] <= 0 and b[i] <= 0) 
			{
				a[i] *= -1;
				b[i] *= -1;
			}
		else if(a[i] >= 0 and b[i] < 0)
			{
				a[i] *= -1;
				b[i] *= -1;
			}
		m[{a[i],b[i]}]++;
	}
	int maks = 0;
	for(auto it: m)
		maks = max(maks, it.second);
	cout << maks + ans;
	
	return 0;
}