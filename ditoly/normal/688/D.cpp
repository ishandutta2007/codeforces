#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 1000000
int f[MN+5],p[MN+5],pn,s[MN+5];
int main()
{
	int n,k,i,j,cnt;
	for(i=2;i<=MN;++i)
	{
		if(!f[i])f[i]=i,p[++pn]=i;
		for(j=1;i*p[j]<=MN;++j){f[i*p[j]]=p[j];if(i%p[j]==0)break;}
	}
	n=read();k=read();
	while(n--)for(i=read();i>1;)
	{
		for(j=f[i],cnt=0;f[i]==j;i/=j)++cnt;
		s[j]=max(s[j],cnt);
	}
	while(k>1)
	{
		for(j=f[k],cnt=0;f[k]==j;k/=j)++cnt;
		if(s[j]<cnt)return 0*puts("No");
	}
	puts("Yes");
}