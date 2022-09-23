#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		ll s = 0;
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			s += a;
			if(s < i * (i - 1) / 2) ok = false;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}