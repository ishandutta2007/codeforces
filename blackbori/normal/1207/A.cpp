#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, b, p, f, h, c, i, s;
	
	scanf("%d", &t);
	
	for(; t--; ){
		scanf("%d%d%d%d%d", &b, &p, &f, &h, &c);
		b /= 2;
		for(i=0, s=0; i<=p && i<=b; i++){
			s = max(s, i * h + min(f, b - i) * c);
		}
		printf("%d\n", s);
	}
	
	
	return 0;
}