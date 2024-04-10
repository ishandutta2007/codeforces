#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
int n;
int d[100005];
int main()
{
	scanf("%d", &n);
	ll sum = 0;
	for(int i = 1; n >= i; ++i)
	{
		scanf("%d", &d[i]);
		sum += (ll) d[i] * (n - d[i] + 1);
	}
	for(int i = 1; n > i; ++i)
	{
		int mini = min(d[i], d[i + 1]);
		int maxi = max(d[i], d[i + 1]);
		sum -= (ll) mini * (n - maxi + 1);
	}
	printf("%lld", sum);
		
	
	return 0;
}