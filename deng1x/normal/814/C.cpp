#include<bits/stdc++.h>

const int N = 1510;
const int M = 26;

char s[N];
int ans[N][M];
int pre[N][M];
int test, n;

bool check(int fill, int target, int ch){
	for (int i = 0; i <= n - target; ++ i){
		if (pre[i + target][ch] - pre[i][ch] + fill >= target){
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d%s", &n, s + 1);
	for (int i = 0; i < M; ++ i){
		for (int j = 1; j <= n; ++ j){
			pre[j][i] = pre[j - 1][i] + (s[j] == 'a' + i);
		}
	}
	for (int i = 0; i < M; ++ i){
		for (int j = 1, k = 0; j <= n; ++ j){
			while (check(j, k, i)){
				++ k;
			}
			ans[j][i] = k;
		}
	}
	scanf("%d", &test);
	while (test --){
		int num;
		scanf("%d%s", &num, s);
		printf("%d\n", ans[num][s[0] - 'a'] - 1);
	}
	return 0;
}