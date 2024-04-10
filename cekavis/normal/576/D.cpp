#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 152;
int n, m, u[N], v[N], w[N], p[N];
struct matrix{
	bitset<N> a[N];
	matrix operator*(const matrix &r)const{
		matrix ans;
		for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(a[i][j])
			ans.a[i]|=r.a[j];
		return ans;
	}
} now, A, I, f[10];
matrix Pow(matrix x, int y){
	matrix ans=I;
	for(; y; y>>=1, x=x*x) if(y&1) ans=ans*x;
	return ans;
}
void solve(int t){
	f[0]=A;
	for(int i=1; i<=8; ++i) f[i]=f[i-1]*f[i-1];
	if(!(now*f[8]).a[1][n]) puts("Impossible");
	else{
		for(int i=8; ~i; --i) if(!(now*f[i]).a[1][n]) t+=1<<i, now=now*f[i];
		printf("%d\n", t+1);
	}
	exit(0);
}
bool cmp(int x, int y){ return w[x]<w[y];}
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; ++i) scanf("%d%d%d", u+i, v+i, w+i), p[i]=i;
	A.a[n][n]=1;
	for(int i=1; i<=n; ++i) I.a[i][i]=1;
	now=I;
	sort(p+1, p+m+1, cmp);
	for(int i=1; i<=m; ++i){
		matrix tmp=Pow(A, w[p[i]]-w[p[i-1]]);
		if((now*tmp).a[1][n]) solve(w[p[i-1]]);
		now=now*tmp;
		A.a[u[p[i]]][v[p[i]]]=1;
	}
	solve(w[p[m]]);
	return 0;
}