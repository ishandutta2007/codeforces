#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	int m = INT_MAX;
	int ans = 0;
	int n; scanf("%d", &n); for(int i = 0; i < n; ++i) {
		int a, p;
		scanf("%d%d", &a, &p);
		m = min(m, p);
		ans += a * m;
	}
	printf("%d\n", ans);
    return 0;
}