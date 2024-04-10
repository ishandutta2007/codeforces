#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 222222;

int n;
int a[N];
long long ans = 0;

int main() {
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0) {
			ans += cnt;
		} else {
			cnt++;
		}
	}
	
	printf("%I64d\n", ans);
	return 0;
}