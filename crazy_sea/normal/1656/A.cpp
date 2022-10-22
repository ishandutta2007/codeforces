#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
int T,n,a[1000010],w1,w2;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		w1=w2=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]<a[w1]) w1=i;
			if(a[i]>a[w2]) w2=i;
		}
		printf("%d %d\n",w1,w2);
	}
}