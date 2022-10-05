/*
nm11
k
1

pp
1n,m1000,0k<max(n,m)

*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1009;
int flag1[maxn], flag2[maxn], mat[maxn][maxn], tmp[maxn][maxn];
int n, m, K, a, b, c, flag, MOD, ans = 1, cnt, cnt1, res, C[maxn][maxn];

int main(){
	scanf("%d%d", &n, &m);
	if (n%2 != m%2){
		puts("0"); return 0;
	}
	scanf("%d", &K);
	for (int i=1; i<=K; i++){
		scanf("%d%d%d", &a, &b, &c);
		flag1[a] = 1; flag2[b] = 1;
		mat[a][b] = c;
	}
	scanf("%d", &MOD);
	
	for (int i=1; i<=n; i++)
		if (!flag1[i]){
			flag = i; break;
		}
	if (!flag){
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				tmp[j][i] = mat[i][j];
		swap(n, m);
		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++)
				mat[i][j] = tmp[i][j];
			if (!flag2[i]) flag = i; 
		}
	}
	
	C[0][0] = 1;
	for (int i=1; i<=n||i<=m; i++){
		C[i][0] = 1;
		for (int j=1; j<=i; j++)
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}
	
	for (int i=1; i<=n; i++){
		if (flag == i) continue;
		cnt = cnt1 = 0;
		for (int j=1; j<=m; j++)
			if (!mat[i][j]) cnt++;
			else if (mat[i][j] == -1) cnt1++;
		res = 0;
		for (int j=1-(cnt1&1); j<=cnt; j+=2)
			res = (res + C[cnt][j]) % MOD;
		ans = 1LL * ans * res % MOD;
	}
	printf("%d\n", ans);
	
	return 0;
}