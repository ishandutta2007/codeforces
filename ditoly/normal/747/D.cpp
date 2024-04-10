#include<cstdio>
inline int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
#include<algorithm>
using namespace std;
#define MN 200000
int a[MN+5],s[MN+5],c[MN+5];
int main()
{
	int n,k,i,j=0,ans=0,ck,ans2=0;
	n=read();k=read();
	for(i=1;i<=n;++i)a[i]=read()<0;
	for(i=1;i<=n;++i){if(a[i]!=a[j])a[++j]=a[i];++s[j];}
	if(!(n=j))return 0*puts("0");
	for(i=1;i<=n;i+=2)if((k-=s[i])<0)return 0*puts("-1");
	ck=k;ans=n;
	for(i=2,j=0;i<n;i+=2)c[j++]=s[i];
	sort(c,c+j);
	for(i=0;i<j&&k>=c[i];++i)k-=c[i],ans-=2;
	if(!a[n]&&ck>=s[n])
	{
		ck-=s[n];ans2=n-1;
		for(i=0;i<j&&ck>=c[i];++i)ck-=c[i],ans2-=2;
		if(ans2<ans)ans=ans2;
	}
	printf("%d",ans);
}