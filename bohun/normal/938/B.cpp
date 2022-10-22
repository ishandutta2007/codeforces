#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int n;
int main()
{
	int ans = 0;
	cin >> n;
	int a;
	for(int i = 1; n >= i; ++i)
	{
		cin >> a;
		ans = max(ans , min(abs(a - 1), abs(a - 1000000)));
	}
	cout << ans;
}