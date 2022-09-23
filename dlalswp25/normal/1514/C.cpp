#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int gcd(int a, int b) { while(b) { a %= b; swap(a, b); } return a; }

int main() {
	int N; scanf("%d", &N);
	vector<int> ans;
	ll t = 1;
	for(int i = 1; i <= N; i++) {
		if(gcd(i, N) == 1) {
			ans.push_back(i);
			t = t * i % N;
		}
	}
	if(t != 1) ans.pop_back();
	printf("%d\n", ans.size());
	for(int i : ans) printf("%d ", i); puts("");
	return 0;
}