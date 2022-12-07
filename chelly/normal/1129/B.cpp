#include<bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	int k;
	scanf("%d", &k);
	a = b = 0;
	for(;;) {
		if(1999 * a - 2000 * b < k) {
			a += 1;
		}else if(1999 * a - 2000 * b > k) {
			a += 1; b += 1;
		}else break;
	}
	if(b == 0) a += 2000, b += 1999;
	printf("2000\n");
	for(int i(0); i < 1998; i++) printf("%d ", 0);
	printf("%d %d\n", -b, a);
}