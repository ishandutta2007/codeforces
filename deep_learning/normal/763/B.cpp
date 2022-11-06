#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("763B.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	printf("YES\n");
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d; 
		scanf("%d%d%d%d", &a, &b, &c, &d); 
		if (!(a % 2) && !(b % 2))
			printf("1\n");
		else if (!(c % 2) && !(d % 2))
			printf("3\n");
		else if (!(a % 2) && !(d % 2))
			printf("2\n");
		else
			printf("4\n");
	}
	return 0; 
}