#include<cstdio>
int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#include<algorithm>
using namespace std;
#define MAX 200000
struct car{int c,v;}c[MAX+5];
bool cmp(car a,car b){return a.v<b.v;}
int g[MAX+5],k,t;
bool check(int v)
{
	int i,s;long long ct=0;
	for(i=0;i++<=k;)
	{
		s=g[i]-g[i-1];
		if(s>v)return false;
		if(s*2<=v)ct+=s;
		else ct+=3*(long long)s-v;
		if(ct>t)return false;
	}
	return true;
}
int main()
{
	int n,i,l,r,mid,res=-1,ans;
	n=read();k=read();g[k+1]=read();t=read();
	for(i=0;i<n;i++)c[i].c=read(),c[i].v=read();
	sort(c,c+n,cmp);
	for(i=1;i<=k;i++)g[i]=read();
	sort(g+1,g+k+1);
	l=0;r=n-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(c[mid].v))res=mid,r=mid-1;
		else l=mid+1;
	}
	if(res<0)return 0*puts("-1");
	ans=c[res].c;
	for(i=res+1;i<n;i++)if(c[i].c<ans)ans=c[i].c;
	printf("%d",ans);
}