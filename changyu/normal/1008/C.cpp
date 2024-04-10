#include<cstdio>
#include<algorithm>
int n,a[100001],t[100001],k,s[100001],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",t+i);
	std::sort(t+1,t+1+n);
	for(int i=1;i<=n;i++)a[i]=t[i];
	for(int i=1,j=1;i<=n;i++)if(t[i]!=t[i-1])t[++k]=t[i];
	for(int i=1;i<=n;i++)a[i]=std::lower_bound(t+1,t+1+k,a[i])-t;
	k=0;
	for(int i=1,j=1;i<=n;i++)
	{
	  if(a[i]!=a[i-1]){
		for(int o=j;o<i;o++)s[++k]=a[o];
		j=i;
	  }
	  k?k--:ans++;
	}printf("%d",n-ans);
	return 0;
}