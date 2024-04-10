#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int a[55];
 
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		sort(a + 1, a + n + 1);
		bool flag = true;
		for(int i = 1; i < n; i++) {
			if(a[i + 1] - a[i] > 1) {
				flag = false;
				break;
			}
		}
		flag ? puts("YES") : puts("NO");
	}
	return 0;
}