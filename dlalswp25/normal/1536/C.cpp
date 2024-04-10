#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
char A[505050];
map<pii, int> mp;

int gcd(int a, int b) { while(b) { a %= b; swap(a, b); } return a; }

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		mp.clear();
		scanf("%d", &N);
		scanf("%s", A + 1);
		int d = 0, k = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] == 'D') d++;
			else k++;
			int g = gcd(d, k);
			printf("%d ", ++mp[{d / g, k / g}]);
		}
		puts("");
	}
	return 0;
}