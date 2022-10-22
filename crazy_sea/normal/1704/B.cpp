#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int n,T,x,a,mn,mx,ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(i==1) mn=mx=a;
			else mn=min(mn,a),mx=max(mx,a);
			if(mx-mn>2*x) ans++,mn=mx=a;
		}
		printf("%d\n",ans);ans=0;
	}
}