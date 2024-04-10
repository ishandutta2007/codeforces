#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 300005
#define maxp 19
#define ll long long 
using namespace std;

int n,m,i,j,k,a[maxn],st;
ll f[maxp][maxn];

int main(){
	scanf("%d",&n);
	for(m=0;m<=20;m++) if (1<<m==n) break; 
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (a[i]<0) st=i;
	}
	memset(f,127,sizeof(f));
	for(k=0;k<=m;k++) if (1<<k+1>st) break;
	for(i=st;i<=n;i++) f[k][i]=0;
	for(k++;k<=m;k++) {
		for(i=st;i<=n;i++) {
			f[k][i]=f[k][i-1];
			if (i>=1<<k) f[k][i]=min(f[k][i],f[k-1][i-1]+a[i]);
		} 
	}
	printf("%I64d",f[m][n]);
}