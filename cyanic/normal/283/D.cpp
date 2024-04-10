/*
*(x,y)xy
(a1,a2),(a2,a3),..,(an-1,an)

n

n<=5000

a[i]=2^x[i]*y[i]
aj -> ai
x[i]=0, y[j]%y[i]=0
x[i]!=0, y[j]%y[i]=0 && x[i]-x[j]=i-j
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 5009;
LL x[maxn], y[maxn], a;
LL n, f[maxn];

int main(){
	scanf("%I64d", &n);
	for (int i=1; i<=n; i++){
		scanf("%I64d", &a);
		while (a % 2 == 0){
			x[i]++; a >>= 1;
		}
		y[i] = a;
	}
	x[n+1] = 0; y[n+1] = 1;
	for (int i=1; i<=n+1; i++){
		f[i] = 1;
		for (int j=1; j<=i-1; j++)
			if (!x[i] && y[j] % y[i] == 0) f[i] = max(f[i], f[j]+1);
			else if (x[i] && y[j] % y[i] == 0 && (x[i]-x[j]==i-j || x[i]<i-j)) f[i] = max(f[i], f[j]+1);
	}
	printf("%I64d\n", n+1-f[n+1]);
	return 0;
}