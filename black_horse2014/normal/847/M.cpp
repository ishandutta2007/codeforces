#include<bits/stdc++.h>
using namespace std;
const int N = 111;
int t[N];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i ++) scanf("%d", t + i);
	int d = t[1] - t[0];
	int flg = 0;
	for (int i = 2; i < n; i ++) {
		if (t[i] - t[i - 1] != d) {
			flg = 1;
			break;
		}
	}
	printf("%d\n", flg ? t[n - 1] : t[n - 1] + d);
	return 0;
}