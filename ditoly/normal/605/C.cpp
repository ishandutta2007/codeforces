#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
struct node{int a,b;}p[MN+5];
bool cmp(const node&a,const node&b){return a.a==b.a?a.b<b.b:a.a<b.a;}
int x,y,q[MN+5],qn;
double ans=1e18;
double cal(int x,int y){return (double)(p[x].b-p[y].b)/(p[x].a-p[y].a);}
bool check(int a,int b,double k)
{
	double xx=x/k,yy=y/k;
	if(p[a].a>=xx&&p[a].b>=yy)return true;
	if(p[b].a>=xx&&p[b].b>=yy)return true;
	if(max(p[a].a,p[b].a)<xx||
	   max(p[a].b,p[b].b)<yy)return false;
	double z=(double)(xx-p[b].a)/(p[a].a-p[b].a);
	if(z*p[a].b+(1-z)*p[b].b>=yy)return true;
	z=(double)(yy-p[b].b)/(p[a].b-p[b].b);
	if(z*p[a].a+(1-z)*p[b].a>=xx)return true;
	return false;
}
double t(int a,int b)
{
	double l=0,r=1e6,mid;
	for(int T=100;T--;)
	{
		mid=(l+r)/2;
		if(check(a,b,mid))r=mid;
		else l=mid;
	}
	ans=min(ans,r);
	return r;
}
int main()
{
	int n,i,j,k,l,r;
	bool fucker=1;
	n=read();x=read();y=read();
	for(i=1;i<=n;++i)p[i].a=read(),p[i].b=read();
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;++i)
	{
		while(qn&&p[i].b>=p[q[qn]].b)--qn;
		while(qn>1&&cal(i,q[qn])-cal(q[qn],q[qn-1])>-1e-7)--qn;
		q[++qn]=i;
	}
	for(t(q[1],q[i=1]);i<qn;++i)t(q[i],q[i+1]);
	printf("%.10lf",ans);
}