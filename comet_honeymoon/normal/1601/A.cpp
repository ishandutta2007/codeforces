#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 200005;
int n;
int a[maxn];
int cnt[60];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		for (int d = 0; d < 30; d++) cnt[d] = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			for (int d = 0; d < 30; d++)
				if ((a[i] >> d) & 1) cnt[d]++;
		}
		for (int i = 1; i <= n; i++) {
			bool flg = 1;
			for (int j = 0; j < 30; j++)
				if (cnt[j] % i) flg = 0;
			if (flg) printf("%d ", i);
		}
		printf("\n");
	}
}