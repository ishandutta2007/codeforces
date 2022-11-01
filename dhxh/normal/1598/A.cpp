#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

int n, m, t;

char a[3][maxn];
bool vis[3][maxn];

int main() {
	int i, j;

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		for(i=1;i<=n;i++) scanf(" %c", &a[1][i]);
		for(i=1;i<=n;i++) scanf(" %c", &a[2][i]);

		bool flag = true;
		for(i=1;i<=n;i++){
			if(a[1][i] == '1' and a[2][i] == '1'){
				flag = false;
			}
		}
		printf(flag ? "YES\n" : "NO\n");
	}

	return 0;
}