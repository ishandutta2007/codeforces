#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		int t = 1;
		while(N) {
			if(N % 10) v.push_back(N % 10 * t);
			t *= 10;
			N /= 10;
		}
		printf("%d\n", v.size());
		for(int i : v) printf("%d ", i);
		puts("");
		v.clear();
	}
	return 0;
}