#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;

int main()
{
	int n;
	char s[100005];
	scanf("%d %s", &n, s);
	ll ans = 0;
	for(int i = 0; n > i; ++i)
	{
		int c = s[i] - '0';
		if(c % 2 == 0)
			ans += i + 1;
	}
	cout << ans;
	return 0;
}