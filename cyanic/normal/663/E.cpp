/*
n*m01.
(0<->1)
1
n<=20, m<=100000 

tf(A) = (tf(A0) + tf(A1), tf(A0) - tf(A1))
utf(A) = (utf((A0+A1) / 2), utf((A0-A1)/2))
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 20;
const int maxm = 100009;
LL cnt[1<<maxn], v[1<<maxn], ans[1<<maxn], res = 4e18;
LL n, m, s[maxn][maxm], a[maxm], t;
char ch;

void FWT(LL a[], int n){
	LL x, y;
	for (int d=1; d<n; d<<=1)
		for (int m=d<<1, i=0; i<n; i+=m)
			for (int j=0; j<d; j++){
				x = a[i+j]; y = a[i+d+j];
				a[i+j] = x + y; a[i+d+j] = x - y;
			}
}

void UFWT(LL a[], int n){
	LL x, y;
	for (int d=1; d<n; d<<=1)
		for (int m=d<<1, i=0; i<n; i+=m)
			for (int j=0; j<d; j++){
				x = a[i+j]; y = a[i+d+j];
				a[i+j] = (x + y) >> 1;
				a[i+d+j] = (x - y) >> 1;
			}
}

void calc(LL A[], LL B[], LL C[], int n){
	FWT(A, n); FWT(B, n);
	for (int i=0; i<=n-1; i++) C[i] = A[i] * B[i];
	UFWT(C, n);
}

int main(){
	scanf("%I64d%I64d%*c", &n, &m);
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++)
			s[i][j] = getchar() - '0';
		getchar();
	}
	for (int i=0; i<m; i++){
		a[i] = 0;
		for (int j=0; j<n; j++)
			a[i] = (a[i] << 1) + s[j][i];
		cnt[a[i]]++;
	}
	for (int i=0; i<(1<<n); i++){
		t = i;
		while (t){
			v[i] += t & 1; t >>= 1;
		}
		v[i] = min(v[i], n-v[i]);
	}
	calc(cnt, v, ans, 1<<n);
	for (int i=0; i<(1<<n); i++)
		res = min(res, ans[i]);
	printf("%I64d\n", res);
	return 0;
}