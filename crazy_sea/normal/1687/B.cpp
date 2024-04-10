#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3e3+10;
int n,m,p[N],a[N],b[N],s,ans;
void add(int x){b[x]=1;}
void del(int x){b[x]=0;}
int ask()
{
	printf("? ");
	for(int i=1;i<=m;i++) printf("%d",b[i]);
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		add(i);
		a[i]=ask();
		del(i);
		p[i]=i;
	}
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		add(p[i]);
		s=ask();
		if(s!=ans+a[p[i]]) del(p[i]);
		else ans=s;
	}
	printf("! %d",ans);
}