#include<bits/stdc++.h>
#define MaxN 200123

int n,m;
int a[MaxN],b[MaxN];
int s[MaxN],t[MaxN],f[MaxN];
int main()
{
	scanf("%d%d",&n,&m);
	if(m==1)return printf("%d\n",n),0;
	for(int i=0;i<n;++i)scanf("%d",a+i);
	for(int i=0;i<m;++i)scanf("%d",b+i);
	for(int i=1;i<n;++i)s[i]=a[i]-a[i-1];
	for(int i=1;i<m;++i)t[i]=b[i]-b[i-1];
	
	for(int i=2,j=0;i<m;++i)
	{
		while(j&&t[j+1]!=t[i])j=f[j];
		if(t[j+1]==t[i])++j;
		f[i]=j;
	}
	
	int ans=0;
	for(int i=1,j=0;i<n;++i)
	{
		while(j&&t[j+1]!=s[i])j=f[j];
		if(t[j+1]==s[i])++j;
		if(j==m-1)++ans,j=f[j];
	}
	printf("%d\n",ans);
	return 0;
}