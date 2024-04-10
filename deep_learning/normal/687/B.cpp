#include <iostream>
#include <cstdio>
using namespace std; 
typedef long long ll; 
ll gcd(ll a, ll b)
{
	if (!b)
		return a; 
	return gcd(b, a % b); 
}
ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}
int main()
{
	// freopen("B.in", "r", stdin); 
	int n, k; 
	scanf("%d%d", &n, &k); 
	ll cur = 1; 
	for (int i = 0; i < n; i++)
	{
		int x; 
		scanf("%d", &x); 
		cur = gcd(k, lcm(cur, x)); 
	}
	if (cur == k)
		printf("Yes\n");
	else
		printf("No\n");
	return 0; 
}