#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;

int n;
int t[100005];
int main()
{
	cin >> n;
	for(int i = 1; n >= i; ++i)
		cin >> t[i];
	int ans = 0;
	int next = 0;
	for(int i = 1; n >= i; ++i)
	{
		if(next < i)
		{
			ans++;
			next = i;
		}
		next = max(next, t[i]);
	}
	cout << ans;
	
	return 0;
}