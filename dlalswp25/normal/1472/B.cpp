#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		bool one = false;
		int sum = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			sum += a;
			if(a == 1) one = true;
		}
		if(sum & 1) puts("NO");
		else if((N & 1) && !one) puts("NO");
		else puts("YES");
	}
	return 0;
}