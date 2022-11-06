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
typedef long long ll; 
using namespace std; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("715C.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
			printf("2\n");
		else
			putll((ll)(i + 1) * (i + 1) * i - i + 1); 
	}
	return 0; 
}