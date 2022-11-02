#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 2e5 + 5; 
int a[N];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, cnt = 0, now = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = n; i > 0; i--) {
			if(a[i] < a[i + 1]) {
				now = i;
				break;
			}
			cnt++;
		}
		for (int i = now; i > 0; i--) {
			if(a[i] > a[i + 1]) break;
			cnt++;
		}
		printf("%d\n", n - cnt);
	}
	return 0;
}