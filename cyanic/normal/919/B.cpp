#include<bits/stdc++.h>
using namespace std;

int K;

int calc(long long x) {
	int res = 0;
	while (x) 
		res += x % 10, x /= 10;
	return res;
}

int main() {
	scanf("%d", &K);
	for (int i=1; K; i++)
		if (calc(i) == 10) {
			K--;
			if (!K) {
				printf("%d\n", i);
				break;
			}
		}
	return 0;
}