#include<bits/stdc++.h>
using namespace std;

int T, n;
bool used[200005];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= 2 * n + 1; i++) used[i] = 0;
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			if(!used[x]) cnt++, used[x] = 1;
			else if(!used[x + 1]) cnt++, used[x + 1] = 1;
		}
		printf("%d\n", cnt);
	}
}