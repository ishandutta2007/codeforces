#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){return a>b;}
const int N=1e5+10;
int a[N],t[N],len,x,n,m,T,ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		sort(a+1,a+m+1);
		for(int i=1;i<m;i++)
			if(a[i+1]!=a[i]+1) t[++len]=a[i+1]-a[i]-1;
		if(a[1]!=1||a[m]!=n) t[++len]=a[1]-1+(n-a[m]);
		sort(t+1,t+len+1,cmp);
		for(int i=1;i<=len;i++)
		{
			x=t[i]-(i-1)*4;
			if(x>2) ans+=x-1;
			else if(x>0) ans++;
			else break;
		}
		printf("%d\n",n-ans);
		ans=len=0;
	}
}