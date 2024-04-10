#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			if(a < 0) ok = false;
		}
		if(!ok) puts("NO");
		else {
			puts("YES");
			puts("101");
			for(int i = 0; i <= 100; i++) printf("%d ", i); puts("");
		}
	}
	return 0;
}