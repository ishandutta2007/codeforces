#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int a, b; scanf("%d%d", &a, &b);
		if(!a && !b) puts("0");
		else if(a + b & 1) puts("-1");
		else if(a == b) puts("1");
		else puts("2");	
	}
	return 0;
}