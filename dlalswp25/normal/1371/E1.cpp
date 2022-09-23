#include <bits/stdc++.h>
 
using namespace std;
 
int N, P;
int A[2020];
vector<int> v;
int L[2020];
 
int main() {
	scanf("%d%d", &N, &P);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	sort(A + 1, A + N + 1);
 
	int mn = 0;
	for(int i = 1; i <= N; i++) {
		mn = max(mn, A[i] - i + 1);
	}
 
	for(int i = 1; i <= N; i++) L[i] = max(1, A[i] + 1 - mn);
	// for(int i = 1; i <= N; i++) printf("%d ", L[i]); puts("");
 
	for(int i = mn; i <= 2000; i++) {
		bool ok = false;
		for(int j = N; j >= 1; j--) {
			if(((N - L[j] + 1) - (N - j)) % P == 0) ok = true;
		}
		if(ok) continue;
		v.push_back(i);
		for(int j = 1; j <= N; j++) { L[j] = max(1, L[j] - 1); }
	}
	printf("%d\n", v.size());
	for(int i : v) printf("%d ", i); puts("");
	return 0;
}