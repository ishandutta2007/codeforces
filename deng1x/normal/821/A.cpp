#include<bits/stdc++.h>

const int N = 100;

int n;
int a[N][N];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= n; ++ j){
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= n; ++ j){
			if (a[i][j] == 1){
				continue;
			}
			bool flag = false;
			for (int s = 1; s <= n; ++ s){
				for (int t = 1; t <= n; ++ t){
					if (a[i][j] == a[i][s] + a[t][j]){
						flag = true;
					}
				}
			}
			if (!flag){
				return printf("No\n"), 0;
			}
		}
	}
	return printf("Yes\n"), 0;
}