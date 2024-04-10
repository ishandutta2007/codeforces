#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int p;
	scanf("%d", &p);
	int ans = 0;
	for(int i = 1; i < p; i++) {
		int flag = 1;
		int x = 1;
		for(int j = 1; j <= p - 2; j++) {
			x = x * i % p;
			if ((x + p - 1) % p == 0)
				flag = 0;
		}
		ans += flag;
	}
	printf("%d\n", ans);
	return 0;
}