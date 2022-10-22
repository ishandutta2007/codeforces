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
const int nax = 100005;
int n, m;
int t[nax];
int a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; n >= i; ++i)
	{
		cin >> t[i];
		if(t[i] % 2)
			a++;
		else
			b++;
	}
	int ans = 0;
	for(int i = 1; m >= i; ++i)
	{
		cin >> t[i];
		t[i] %= 2;
		if(t[i] == 1)
		{
			if(b)
			{
				ans++;
				--b;
			}
		}
		else
		{
			if(a)
			{
				++ans;
				--a;
			}
		}
	}
	cout << ans;
	
		
	return 0;
}