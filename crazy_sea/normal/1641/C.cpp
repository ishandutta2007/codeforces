#include<cstdio>
#define N 300010
using namespace std;
void getmin(int&a,int b)
{
	if(a>b) a=b;
}
int fa[N],k[N];
int getfa(int a)
{
	if(a==fa[a]) return a;
	else return (fa[a]=getfa(fa[a]));
}
void _merge(int x,int y)
{
	x=getfa(x),y=getfa(y);
	getmin(k[y],k[x]);
	fa[x]=y;
}
int n,T,type,l,r,op,x;
int main()
{
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n+1;i++) fa[i]=i,k[i]=0x3f3f3f3f;
	while(T--)
	{
		scanf("%d",&type);
		if(type==0)
		{
			scanf("%d%d%d",&l,&r,&op);
			if(op==0)
			{
				x=l;
				while(x<=r) _merge(x,x+1),x=getfa(x);
			}
			else if(op==1)
			{
				getmin(k[getfa(l)],r);
			}
		}
		else if(type==1)
		{
			scanf("%d",&x);
			if(getfa(x)!=x) printf("NO");
			else if(getfa(x+1)<=k[x]) printf("N/A");
			else printf("YES");
			printf("\n");
		}
	}
}