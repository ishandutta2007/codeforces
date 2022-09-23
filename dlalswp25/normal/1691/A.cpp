#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		int o = 0, e = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			if(a & 1) o++;
			else e++;
		}
		printf("%d\n", min(o, e));
	}
	return 0;
}