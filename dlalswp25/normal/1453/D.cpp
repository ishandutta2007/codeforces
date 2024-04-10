#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll K; scanf("%lld", &K);
		if(K & 1) { puts("-1"); continue; }
		vector<int> v;
		int s = 0;
		for(int i = 61; i >= 2; i--) {
			while((1LL << i) - 2 <= K) {
				K -= (1LL << i) - 2;
				v.push_back(i - 2);
				s += i - 1;
			}
		}
		printf("%d\n", s);
		for(int i : v) {
			printf("1 ");
			for(int j = 0; j < i; j++) printf("0 ");
		}
		puts("");
	}
	return 0;
}