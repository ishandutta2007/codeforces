/*
nm




*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 300009;
int pa[maxn], vis[maxn], cnt1[maxn], cnt2[maxn];
int u[maxn], v[maxn], n, m, cnt, ans[2][maxn], res1, res2;
char type[maxn];

int getpa(int x){
	return pa[x] == x ? x : pa[x] = getpa(pa[x]);
}

int solve(char t, int k){
	memset(vis, 0, sizeof vis);
	memset(cnt1, 0, sizeof cnt1);
	memset(cnt2, 0, sizeof cnt2);
	for (int i=1; i<=3*n; i++) pa[i] = i;
	for (int i=1; i<=m; i++){
		if (type[i] == t){					//
			if (getpa(u[i]) == getpa(v[i])) return 1e9;
			pa[getpa(u[i]+n)] = getpa(v[i]);
			pa[getpa(v[i]+n)] = getpa(u[i]);
		}
		else{
			if (getpa(u[i]+n) == getpa(v[i])) return 1e9;
			pa[getpa(u[i]+n)] = getpa(v[i]+n);
			pa[getpa(u[i])] = getpa(v[i]);
		}
	}
	for (int i=1; i<=n; i++)
		if (vis[getpa(i)]) cnt1[getpa(i)]++;
		else if (vis[getpa(n+i)]) cnt2[getpa(n+i)]++;
		else {
			vis[getpa(i)] = 1;
			cnt1[getpa(i)] = 1;
		}
	cnt = 0;
	for (int i=1; i<=n; i++)
		if (vis[getpa(i)] && cnt1[getpa(i)] <= cnt2[getpa(i)]) ans[k][++cnt] = i;
		else if (vis[getpa(i+n)] && cnt1[getpa(i+n)] > cnt2[getpa(i+n)]) ans[k][++cnt] = i;
	return cnt;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
		scanf("%d%d %c", &u[i], &v[i], &type[i]);
	res1 = solve('B', 0); res2 = solve('R', 1);
	if (res1 == 1e9 && res2 == 1e9){
		puts("-1"); return 0;
	}
	if (res1 < res2){
		printf("%d\n", res1);
		for (int i=1; i<=res1; i++) printf("%d ", ans[0][i]);
	}
	else{
		printf("%d\n", res2);
		for (int i=1; i<=res2; i++) printf("%d ", ans[1][i]);
	}
	return 0;
}