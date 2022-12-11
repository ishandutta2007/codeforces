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
struct edge{int w,id,u;}e[MN+5];
bool cmp(const edge&a,const edge&b){return a.w==b.w?a.u>b.u:a.w<b.w;}
int x[MN+5],y[MN+5],cnt=1,X=1,Y=1;
bool next()
{
	for(++X;X+2>Y;)++Y,X=1;
	if(Y>cnt)return false;
	return true;
}
int main()
{
	int n,m,i;
	n=read();m=read();
	for(i=1;i<=m;++i)e[i].w=read(),e[i].id=i,e[i].u=read();
	sort(e+1,e+m+1,cmp);
	for(i=1;i<=m;++i)
		if(e[i].u)x[e[i].id]=cnt,y[e[i].id]=++cnt;
		else if(next())x[e[i].id]=X,y[e[i].id]=Y;
		else return 0*puts("-1");
	for(i=1;i<=m;++i)printf("%d %d\n",x[i],y[i]);
}