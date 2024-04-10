#include <stdio.h>
long long ans[5050];
long long sum[5050];
int N, A, B, K;
bool same_direction(int a, int b) {
	if(a == B || b == B) return false;
	if(a < B && b > B) return false;
	if(a > B && b < B) return false;
	return true;
}
long long get_ans(int a) {
	if(!same_direction(A, a)) return 0;
	if(a<B) return sum[(a+B-1)/2]-ans[a];
	else return sum[N]-sum[(a+B)/2]-ans[a];
}
int main() {
	int i, j;
	scanf("%d %d %d %d", &N, &A, &B, &K);
	ans[A] = 1;
	for(i = 1; i <= A-1; i++) sum[i] = 0;
	for(i = A; i <= N; i++) sum[i] = 1;
	for(i = 1; i <= K; i++) {
		for(j = 1; j <= N; j++) {
			ans[j] = get_ans(j);
			ans[j] %= 1000000007;
			if(ans[j] < 0) ans[j] += 1000000007;
		}
		for(j = 1; j <= N; j++) {
			sum[j] = (ans[j]+sum[j-1])%1000000007;
			if(sum[j] < 0) sum[j] += 1000000007;
		}
	}
	printf("%I64d", sum[N]);
	return 0;
}