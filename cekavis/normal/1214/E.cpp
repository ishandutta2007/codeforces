#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n, l, r, a[N], f[N], g[N], q[N*5];
bool cmp(int x, int y){ return a[x]>a[y];}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), f[i]=i;
	sort(f+1, f+n+1, cmp);
	for(int i=1; i<=n; ++i) g[f[i]]=i;
	for(int i=1; i<n; ++i) printf("%d %d\n", f[i]*2-1, f[i+1]*2-1);
	l=N, r=l-1;
	for(int i=1; i<=a[f[1]]; ++i) q[++r]=f[i]*2-1;
	int now=a[f[1]];
	for(int i=1; i<=now; ++i){
		while(r-l+1>a[f[i]]) --r;
		printf("%d %d\n", q[r], f[i]*2);
		if(q[r]&1) now=g[(q[r]+1)/2];
		q[++r]=f[i]*2, ++l;
	}
	--l;
	for(int i=now+1; i<=n; ++i){
		q[--l]=f[i]*2-1;
		while(r-l+1>a[f[i]]) --r;
		printf("%d %d\n", q[r], f[i]*2);
	}
	return 0;
}