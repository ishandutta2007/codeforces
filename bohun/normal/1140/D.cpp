#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;

int n;
	
int main()
{
	cin >> n;
	ll ans = 0;
	for(int i = 2; n - 1 >= i; ++i)
	{
		int A = (i + 1);
		if(A > n)
			A %= n;
		ans += A * i;
	}
	cout << ans;
	return 0;
}