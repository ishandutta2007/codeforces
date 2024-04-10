#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;

const int maxn = 500;
LL p[maxn]; int a[maxn];
int n; LL V, ans, remain, A;
LL res, resA, resB, resC;

void dfs2(LL k, LL v){
	if (v*remain < A || v*v > V/A) return;
	if (k == n+1){
		res = 2*V/A+2*A*(v+V/A/v);
		if (res < ans){ ans = res; resA = A; resB = v; resC = V/A/v; }
		return;
	}
	int tmp = a[k];
	for (int i=1; i<=tmp; i++) remain /= p[k];
	while (a[k] > 0){ a[k]--; v *= p[k]; }
	while (a[k] < tmp){ dfs2(k+1, v); v /= p[k]; a[k]++; }
	dfs2(k+1, v);
	for (int i=1; i<=tmp; i++) remain *= p[k];
}

void solve(LL x){
	if (2*V/x+2*x*2*(LL)sqrt(V/x) >= ans) return;
	remain = V/x; A = x; dfs2(1, 1);
}

void dfs1(LL k, LL v){
	if (k == n+1) { solve(v); return; }
	int tmp = a[k];
	while (a[k] > 0 && v*v <= V/v){ a[k]--; v *= p[k]; }
	if (v*v > V/v) { a[k]++; v /= p[k]; }
	while (a[k] < tmp){ dfs1(k+1, v); v /= p[k]; a[k]++; }
	dfs1(k+1, v);
}

int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d", &n); V = 1; ans = 9e18;
		for (int i=1; i<=n; i++){
			scanf("%I64d%d", &p[i], &a[i]);
			for (int j=1; j<=a[i]; j++) V *= p[i];
		}
		dfs1(1, 1);
		printf("%I64d %I64d %I64d %I64d\n", ans, resA, resB, resC);
	}
	return 0;
}