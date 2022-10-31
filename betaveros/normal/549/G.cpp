// @betaveros :: generated with cpp2.hs
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
int a[200008];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){ scanf("%d", &a[i]); a[i] += i; }
	sort(a, a + n);
	for (int i = 0; i < n - 1; ++i){
		if (a[i] == a[i+1]) {
			printf(":(\n");
			return 0;
		}
	}
	for (int i = 0; i < n; ++i){
		if (i) printf(" ");
		printf("%d", a[i] - i);
	}
	printf("\n");
}