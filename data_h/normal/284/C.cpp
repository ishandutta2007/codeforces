#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 300000;

int add[MAXN];
long long ans = 0;
int size, v[MAXN], n;

int main() {
	scanf("%d", &n);
	size = 0;
	v[size = 1] = 0;
	ans = 0;
	for(int i = 1; i <= n; i++) {
		int t, a, x;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d %d", &a, &x);
			a = min(a, size);
			add[a] += x;
			ans += x * a;
		} else if (t == 2) {
			scanf("%d", &x);
			size++;
			v[size] = x;
			ans += x;
		} else {
			add[size - 1] += add[size];
			ans -= v[size] + add[size];
			add[size] = 0;
			size--;
		}
		printf("%.6f\n", (double)ans / size);
	}
	return 0;
}