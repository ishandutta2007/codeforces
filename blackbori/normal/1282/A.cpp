#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, a, b, c, d, l, r;
	
	scanf("%d", &t);
	
	for(; t --; ){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if(a > b) swap(a, b);		
		l = max(a, c - d); r = min(b, c + d);
		if(l > r) printf("%d\n", b - a);
		else printf("%d\n", b - a - r + l);
	}
	
	return 0;
}