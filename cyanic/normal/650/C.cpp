/*
n*m(n*m<=1,000,000)
n*m





*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000009;
struct node{
	int r, c, v, id;
} p[maxn];
int pa[maxn], X[maxn], Y[maxn], ans[maxn], x[maxn], y[maxn], tmp[maxn];
int n, m, j;

bool cmp(node a, node b){
	return a.v < b.v;
}

int getpa(int x){
	return pa[x] == x ? x : pa[x] = getpa(pa[x]);
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++){
			scanf("%d", &p[(i-1)*m+j].v);
			p[(i-1)*m+j].r = i; p[(i-1)*m+j].c = j;
			p[(i-1)*m+j].id = (i-1)*m+j;
			pa[(i-1)*m+j] = (i-1)*m+j;
		}
	sort(p+1, p+n*m+1, cmp);
	for (int i=1; i<=n*m; i=j){
		for (j=i; p[i].v==p[j].v; ++j);
		for (int k=i; k<j; k++){
			int r = p[k].r, c = p[k].c;
			if (!x[r]) x[r] = k;
			else pa[getpa(k)] = getpa(x[r]);
			if (!y[c]) y[c] = k;
			else pa[getpa(k)] = getpa(y[c]);
		}
		for (int k=i; k<j; k++){
			int q = getpa(k);
			tmp[q] = max(tmp[q], max(X[p[k].r], Y[p[k].c]) + 1);
		}
		for (int k=i; k<j; k++){
			x[p[k].r] = y[p[k].c] = 0;
			X[p[k].r] = Y[p[k].c] = ans[p[k].id] = tmp[getpa(k)];
		}
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++)
			printf("%d ", ans[(i-1)*m+j]);
		puts("");
	}
	return 0;
}