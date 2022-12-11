#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
char s[MN+5];
int main()
{
	int n,i,j,ans=0;
	scanf("%s",s+1);n=strlen(s+1);
	for(i=1;i<=n;i=j)
	{
		for(j=i+1;j<=n&&s[j]!=s[j-1];++j);
		ans=max(ans,j-i);
	}
	if(s[1]!=s[n])
	{
		for(i=2;i<=n&&s[i]!=s[i-1];++i);
		for(j=n-1;j&&s[j]!=s[j+1];--j);
		ans=max(ans,min(n,i-1+n-j));
	}
	printf("%d",ans);
}