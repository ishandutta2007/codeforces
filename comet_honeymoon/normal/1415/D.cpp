#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N;
int A[100005], S[100005];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]), S[i] = S[i - 1] ^ A[i];
	for(int i = 1; i < N; i++) {
		if(i != 1 && A[i - 1] > (A[i] ^ A[i + 1])) { printf("1\n"); return 0; }
		if(i + 1 != N && A[i + 2] < (A[i] ^ A[i + 1])) { printf("1\n"); return 0; }
	}
	int ans = 0x3f3f3f3f;
	for(int l = 1; l <= N; l++)
	for(int r = l + 1; r <= N; r++) {
		if(l != 1 && A[l - 1] > (S[l - 1] ^ S[r])) ans = min(ans, r - l);
		if(r != N && A[r + 1] < (S[l - 1] ^ S[r])) ans = min(ans, r - l);
	}
	for(int l = 1; l <= N; l++)
	for(int r = l + 1; r <= N; r++)
	for(int rr = r + 1; rr <= N; rr++)
		if((S[l - 1] ^ S[r]) > (S[r] ^ S[rr])) ans = min(ans, rr - l - 1);
	if(ans != 0x3f3f3f3f) printf("%d\n", ans);
	else printf("-1\n");
}