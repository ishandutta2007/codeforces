#include<cstdio>
const int N=1e5+1,M=998244353;
int a[N][10],k[N],n,b[11],t,s,Pow10[20];
signed main(){
	Pow10[0]=1;
	for(int i=1;i<20;i++)Pow10[i]=1ll*Pow10[i-1]*10%M;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	  scanf("%d",&t);
	  for(;t;t/=10)a[i][k[i]++]=t%10;
	  b[k[i]]++;
	}
	//for(int j=1;j<=10;j++)printf("%d ",b[j]);puts("");
	for(int i=1;i<=n;i++){
	  for(int j=10;j;j--)
		for(int l=0,p=0;l<k[i];l++,p+=1+(l<=j))
		  s=(s+1ll*a[i][l]*Pow10[p]%M*b[j])%M;
	  for(int j=10;j;j--)
		for(int l=0,p=1;l<k[i];l++,p+=1+(l<j))
		  s=(s+1ll*a[i][l]*Pow10[p]%M*b[j])%M;
	  //printf("%d\n",s);
	}
	printf("%d",s);
	return 0;
}