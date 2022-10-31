#include <bits/stdc++.h>

using namespace std;

int is_fib(int a) {
	int b=1,c=2;
	while(b <= a) {
		if(a == b) return true;
		int t = c;
		c = b+c;
		b = t;
	}
	return false;
}

int main() {
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) {
		if(is_fib(i)) printf("O");
		else printf("o");
	}
	printf("\n");
	return 0;
}