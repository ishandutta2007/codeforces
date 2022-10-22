#include<cstdio>
#define N 500010
using namespace std;
int q[N],to[N],len,x[N],y[N],type,n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&type,&x[i]);
		if(type==2) scanf("%d",&y[i]);
	}
	int mx=5e5;
	for(int i=1;i<=mx;i++) to[i]=i;
	for(int i=n;i;i--)
	{
		if(!y[i]) q[++len]=to[x[i]];
		else to[x[i]]=to[y[i]];
	}
	for(int i=len;i;i--) printf("%d ",q[i]);
}