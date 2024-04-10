#include<cstdio>
const int N=2e5+2;
int n,m,ans,s,k;char a[N];
int main()
{
	scanf("%d%d%s",&n,&m,a+1);
	for(char c=97;c<123;c++){
	  s=0;
	  for(int i=1;i<=n;i++)
		if(a[i-1]==c)
		  if(a[i]!=a[i-1])s+=k/m,k=0;
		  else k++;
		else if(a[i]==c)k=1;
	  s+=k/m;
	  ans=s>ans?s:ans;
	}
	printf("%d",ans);
	return 0;
}