#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,len,ans,a,t[33],T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&len);
		for(int i=0;i<len;i++) t[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			for(int j=0;j<len;j++)
				if(a&(1<<j)) t[j]++;
		}
		for(int i=0;i<len;i++)
			if(t[i]>n/2) ans|=(1<<i);
		printf("%d\n",ans),ans=0;
	}
	return 0;
}