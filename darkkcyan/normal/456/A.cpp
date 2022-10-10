#include <bits/stdc++.h>
using namespace std;

#define maxn 101010
int c[maxn] = {0};
int q[maxn] = {0};
int a[maxn];
int b[maxn];

bool cmpByC(int a, int b) {
	return c[a] < c[b];
}
bool cmpByQ(int a, int b) {
	return q[a] < q[b];
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> c[i] >> q[i], a[i] = b[i] = i;
	sort(a, a + n, cmpByC);
	sort(b, b + n, cmpByQ);
	if (equal(a, a + n, b)) cout << "Poor Alex";
	else cout << "Happy Alex";
	return 0;
}