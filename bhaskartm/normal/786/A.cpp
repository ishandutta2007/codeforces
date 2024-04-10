#include<bits/stdc++.h>
using namespace std;
 
int n;
set<int> A[2];
 
int deg[7002][2];
int dp[7002][2];
bool use[7002][2];
 
inline void dfs(int a, int b){
	use[a][b] = true;
		int pr = b ^ true;
		for (auto it = A[pr].begin(); it != A[pr].end(); it++){
			int go = a + n - (*it);
			if (go >= n)go -= n;
			deg[go][pr]++;
			if (use[go][pr]){
				continue;
			}
			if (dp[a][b] == -1){
				dp[go][pr] = 1;
				dfs(go, pr);
				continue;
			}
			if (deg[go][pr] == A[pr].size()){
				dp[go][pr] = -1;
				dfs(go, pr);
				continue;
			}
		}
}
 
int main(){
	cin >> n;
	{
		int a;
		scanf("%d", &a);
		for (int i = 0; i < a; i++){
			int b;
			scanf("%d", &b);
			A[0].insert(b);
		}
	}
	{
		int a;
		scanf("%d", &a);
		for (int i = 0; i < a; i++){
			int b;
			scanf("%d", &b);
			A[1].insert(b);
		}
	}
	use[0][0] = true;
	use[0][1] = true;
	dp[0][0] = -1;
	dp[0][1] = -1;
	dfs(0, 0);
	dfs(0, 1);
	for (int j = 0; j < 2; j++){
		for (int i = 1; i < n; i++){
			if (i>1)printf(" ");
			if (dp[i][j] == -1){
				printf("Lose");
			}
			if (dp[i][j] == 1){
				printf("Win");
			}
			if (dp[i][j] == 0){
				printf("Loop");
			}
		}
		puts("");
	}
	return 0;
}