#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool used[55];
int print[55], cnt;

int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(used, false, sizeof used);
		cnt = 0;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n * 2; i++) {
			int a;
			scanf("%d", &a);
			if (!used[a]) {
				used[a] = true;
				print[++cnt] = a;
			}
		}
		for (int i = 1; i <= cnt; i++) {
			printf("%d ", print[i]);
		}
		puts("");
	}
	return 0;
}