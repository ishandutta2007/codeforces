#include<cstdio>
#include<algorithm>
#define N 100010
using namespace std;
bool a[N],b[N];
char s1[N],s2[N];
int n,T,ans;
const int inf=0x3f3f3f3f;
int calc1()
{
	int s1,s2;
	s1=s2=0;
	for(int i=1;i<=n;i++)
		if(a[i]&&!b[i]) s1++;
		else if(!a[i]&&b[i]) s2++;
	if(s1==s2) return s1*2;
	else return inf;
}
bool check1()
{
	for(int i=1;i<=n;i++)
		if(a[i]==1) return 1;
	return 0;
}
bool check2()
{
	for(int i=1;i<=n;i++)
		if(b[i]==1) return 1;
	return 0;
}
int calc2()
{
	int s1,s2;s1=s2=0;
	for(int i=1;i<=n;i++)
		if(!a[i]&&!b[i]) s1++;
		else if(a[i]&&b[i]) s2++;
	if(s1+1==s2) return s1+s2;
	else return inf;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s%s",&n,s1,s2);
		for(int i=1;i<=n;i++)
			a[i]=(s1[i-1]=='1'),
			b[i]=(s2[i-1]=='1');
		if(check1()^check2())
		{puts("-1");continue;}
		ans=min(calc1(),calc2());
		if(ans==inf) printf("-1");
		else printf("%d",ans);
		putchar('\n');
	}
}