#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if (n % 2 == 0) {
		printf("%d %d\n", 4, n - 4);
	} else {
		for(int i = 4; ; i += 2) {
			if ((n - i) % 3 == 0) {
				printf("%d %d\n", i, n - i);
				return 0;
			}
		}
	}
	return 0;
}