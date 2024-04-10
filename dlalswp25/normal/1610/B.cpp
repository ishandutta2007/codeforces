#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int A[202020];

pii chk(int x) {
	int l = 1, r = N;
	while(l <= r) {
		while(l <= N && A[l] == x) l++;
		while(r >= 1 && A[r] == x) r--;
		if(l > r) { return {-1, -1}; }
		if(A[l] == A[r]) { l++; r--; continue; }
		return {l, r};
	}
	return {-1, -1};
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		pii t = chk(0);
		if(t.first == -1) { puts("YES"); continue; }
		int a = A[t.first], b = A[t.second];
		if(chk(a).first == -1 || chk(b).first == -1) { puts("YES"); continue; }
		puts("NO");
	}
	return 0;
}