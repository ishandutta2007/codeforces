#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		bool ok = false;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			bool sq = false;
			for(int j = 1; j <= 100; j++) if(j * j == a) sq = true;
			if(!sq) ok = true;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}