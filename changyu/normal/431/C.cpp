#include<cstdio>
#include<cstring>
const int N=101,M=1e9+7;
int f[N],n,m,t;
int s(int n,int m){
	memset(f,0,sizeof f);
	f[0]=1;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m&&j<=i;j++)
		f[i]=(f[i]+f[i-j])%M;
	return f[n];
}
int main(){
	scanf("%d%d%d",&n,&m,&t);
	printf("%d",(s(n,m)-s(n,t-1)+M)%M);
	return 0;
}