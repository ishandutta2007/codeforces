#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 22
#define mo 31607
using namespace std;

int n,i,j,k,a[maxn][maxn];

int ksm(int x,int y){
	int s=1;
	for(;y;y/=2,x=x*x%mo) if (y&1)
		s=s*x%mo;
	return s;
}

int bz[maxn][maxn],f[maxn][maxn],ans;
void dg(int x,int s){
	if (x==n){
		for(int i=0;i<n;i++) s=s*(1-f[x][i])%mo; 
		(ans+=s)%=mo; return;
	}
	for(int i=0;i<n;i++) f[x+1][i]=f[x][i]*((!bz[i][x])?a[i][x]:1)%mo;
	dg(x+1,s);
	for(int i=0;i<n;i++) {if (!bz[i][x]) s=s*a[i][x]%mo;bz[i][x]++;}
	for(int i=0;i<n;i++) f[x+1][i]=f[x][i]*((!bz[i][x])?a[i][x]:1)%mo;
	dg(x+1,-s);
	for(int i=0;i<n;i++) bz[i][x]--;
}

int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++) for(j=0;j<n;j++)
		scanf("%d",&a[i][j]),a[i][j]=a[i][j]*ksm(10000,mo-2)%mo;
	for(int t1=0;t1<2;t1++) for(int t2=0;t2<2;t2++){
		int s=1;
		memset(bz,0,sizeof(bz));
		if (t1) 
			for(i=0;i<n;i++) if (!bz[i][i]) s=s*a[i][i]%mo,bz[i][i]=1;
		if (t2)
			for(i=0;i<n;i++) if (!bz[i][n-i-1]) s=s*a[i][n-i-1]%mo,bz[i][n-i-1]=1;
		for(i=0;i<n;i++) f[0][i]=1;
		dg(0,s*(((t1+t2)&1)?-1:1));
	}
	printf("%d\n",(1-ans%mo+mo)%mo);
}