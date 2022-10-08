#include <stdio.h>
int gcd(int a, int b) {
	return (a==0)?b:gcd(b%a, a);
}
int main() {
	int N, i, GCD, mx, t;
	scanf("%d %d", &N, &GCD);
	mx = GCD;
	for(i = 2; i <= N; i++) {
		scanf("%d", &t);
		GCD = gcd(GCD, t);
		mx = (mx>t)?mx:t;
	}
	if((mx/GCD-N)%2==1) printf("Alice");
	else printf("Bob");
	return 0;
}