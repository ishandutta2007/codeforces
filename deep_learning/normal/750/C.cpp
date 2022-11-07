#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;  
int main()
{
#ifndef ONLINE_JUDGE
	freopen("750C.in", "r", stdin); 
#endif
	int n, off = 0, mn = -0x3FFFFFFF, mx = 0x3FFFFFFF; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		int c, d; 
		scanf("%d%d", &c, &d); 
		if (d - 1)
			mx = min(mx, 1900 - off); 
		else
			mn = max(mn, 1900 - off); 
		off += c; 
	}
	if (mx <= mn)
		printf("Impossible\n");
	else if (mx == 0x3FFFFFFF)
		printf("Infinity\n");
	else
		printf("%d\n", mx + off - 1);
	return 0; 
}