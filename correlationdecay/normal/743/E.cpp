#include <bits/stdc++.h>
#define maxn 1009
using namespace std;
int n;
int a[maxn<<1];
int cnt[maxn<<1], rk[maxn<<1];
int pos[maxn<<1][10];
int tmp[10], R[maxn<<1][10];
int ans;
int f[maxn][1<<8];
const int INF = 1e9;
int dfs(int u, int st, int  m){
	if(f[u][st] != -1)
		return f[u][st];
	if(st == 0){
		return 0;
	}
	if(u > n){
		return -INF;
	}
	int &ans = f[u][st];
	ans = -INF;
	for(int i = 1; i <= 8; i++){
		if(st & (1 << (i - 1))){
			if(R[u][i] == -1){
				if(m == 1){
					ans = max(ans, dfs(u, st^(1<<(i-1)),m));
				}
				else{
					return ans = -INF;
				}
			}
			int from = R[u][i];
			int to = pos[rk[from] + m - 1][i];
			if(to != -1){
				ans = max(ans, dfs(to + 1, st ^ (1 << (i - 1)), m) + m);
			}
			if(m == 1){
				ans = max(ans, dfs(u, st ^ (1 << (i - 1)), m));
			}
			else{
				to = pos[rk[from] + m - 1 -1][i];
				if(to != -1)
					ans = max(ans, dfs(to + 1, st ^ (1 << (i - 1)), m) + m - 1);
			}
		}
	}
	return ans;	
}
bool check(int m){
	memset(f, -1, sizeof(f));
	int res = dfs(1, (1 << 8) - 1, m);
	ans = max(ans, res);
	return res >= 0;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	for(int i = 1; i <= n; i++){
		cnt[a[i]]++;
		rk[i] = cnt[a[i]];
	}

	memset(pos, -1, sizeof(pos));

	for(int i = 1; i <= n; i++){
		pos[rk[i]][a[i]] = i;
	}

	memset(tmp, -1, sizeof(tmp));

	for(int i = n; i >= 1; i--){
		tmp[a[i]] = i;
		for(int j = 1; j <= 8; j++){
			R[i][j] = tmp[j];
		}
	}

	
	int L = 1, R = 1000;
	
	while(L < R){
		int M = (L + R + 1) >> 1;
		if(check(M))
			L = M;
		else
			R = M - 1;
	}
	
	check(L);


	cout << ans << endl;
	//system("pause");
	return 0;
}