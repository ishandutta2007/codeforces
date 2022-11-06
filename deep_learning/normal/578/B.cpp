#include <iostream>
#include <cstdio>
using namespace std; 
typedef long long ll; 
int pre[204800], suf[204800], arr[204800]; 
int main()
{
	// freopen("578B.in", "r", stdin);
	int n, k, x; 
	scanf("%d%d%d", &n, &k, &x); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		pre[i] = (i ? pre[i - 1] : 0) | arr[i]; 
	}
	for (int i = n - 1; i >= 0; i--)
		suf[i] = suf[i + 1] | arr[i];
	ll mul = 1; 
	for (int i = 0; i < k; i++)
		mul *= x;  
	ll ans = 0; 
	for (int i = 0; i < n; i++)
		ans = max(ans, (mul * arr[i]) | (i ? pre[i - 1] : 0) | suf[i + 1]); 
	cout << ans << endl; 
	return 0; 
}