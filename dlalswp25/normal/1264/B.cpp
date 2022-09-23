#include <bits/stdc++.h>

using namespace std;

int a[4];
int b[4];
int x, y, z;
bool ok;

vector<int> ans;

void put(int x) {
	ans.push_back(x);
	if(!b[x]) ok = false;
	b[x]--;
}

int main() {
	scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
	int mn = 3, mx = 0;
	for(int k = 3; k >= 0; k--) if(a[k]) mn = k;
	for(int k = 0; k <= 3; k++) if(a[k]) mx = k;

	for(int i = 0; i <= 3; i++) {
		for(int j = i; j <= 3; j++) {

			// printf("%d %d\n", i, j); 
			ans.clear();
			ok = true;
			for(int k = 0; k <= 3; k++) b[k] = a[k];

			for(int k = i; k >= mn; k--) put(k);

			for(int k = mn; k < j; k++) {
				while(b[k] > 0) {
					put(k + 1); put(k);
				}
				put(k + 1);
			}

			for(int k = j; k < mx; k++) {
				while(b[k] > 1) {
					put(k + 1); put(k);
				}
				put(k + 1);
			}

			for(int k = mx - 1; k >= j; k--) put(k);

			if(b[0] || b[1] || b[2] || b[3] || !ok) continue;

			puts("YES");
			for(int k : ans) printf("%d ", k); puts("");
			return 0;
		}
	}
	puts("NO");
	return 0;
}