#include<cstdio>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

int n, k;

int calc(int x) {
	return x / k + (x % k > 0);
}
int main() {
	scanf("%d %d", &n, &k);	
	printf("%d\n", calc(n * 2) + calc(n * 5) + calc(n * 8));
}