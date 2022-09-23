#include <bits/stdc++.h>

using namespace std;

int N;
int A[5050];

int f(int l, int r, int x) {
	if(r < l) return 0;
	int mn = *min_element(A + l, A + r + 1);

	if(mn - x >= r - l + 1) return r - l + 1;
	int ret = mn - x;
	int bef = l - 1;
	for(int i = l; i <= r; i++) {
		if(A[i] == mn) {
			ret += f(bef + 1, i - 1, mn);
			bef = i;
		}
	}
	ret += f(bef + 1, r, mn);
	return min(ret, r - l + 1);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	printf("%d\n", f(1, N, 0));
	return 0;
}