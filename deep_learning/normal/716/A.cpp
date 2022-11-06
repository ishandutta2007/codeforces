#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#ifdef ONLINE_JUDGE
#define inpll(x) scanf("%I64d", &x); 
#define putll(x) printf("%I64d\n", x);
#define putlls(x) printf("%I64d ", x);
#else
#define inpll(x) scanf("%lld", &x); 
#define putll(x) printf("%lld\n", x);
#define putlls(x) printf("%lld ", x);
#endif
using namespace std; 
int arr[102400]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("715A.in", "r", stdin); 
#endif
	int n, c; 
	scanf("%d%d", &n, &c); 
	int cur = 0; 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		if (i && arr[i] - arr[i - 1] > c)
			cur = 0; 
		cur++; 
	}
	printf("%d\n", cur);
	return 0; 
}