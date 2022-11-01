#include <bits/stdc++.h>

using namespace std;

int n, m, t;

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int ans = 0;
		ans = max(ans, min(a, b) * min(c, d));
		ans = max(ans, min(a, c) * min(b, d));
		ans = max(ans, min(a, d) * min(c, b));
		
		printf("%d\n", ans);
	}
	
	return 0;
}