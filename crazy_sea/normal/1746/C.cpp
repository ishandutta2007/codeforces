#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int a[N],b[N],x[N],t[N],n,T,len;
bool cmp(int x,int y)
{
	return b[x]>b[y];
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i]-a[i-1];
		for(int i=1;i<=n;i++)
			if(b[i]<0) t[++len]=i;
		sort(t+1,t+len+1,cmp);
		int m=n;
		while(len>m/2) x[m--]=t[len--];
		for(int i=1;i<=len;i++)
			x[i]=x[m+1-i]=t[i];
		for(int i=1;i<=n;i++)
			if(!x[i]) x[i]=n;
		for(int i=1;i<=n;i++) printf("%d ",x[i]);
		printf("\n");
		for(int i=1;i<=n;i++) x[i]=0;
		len=0;
	}
}