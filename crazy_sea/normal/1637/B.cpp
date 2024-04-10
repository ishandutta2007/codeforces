#include<cstdio>
using namespace std;
int n,a,T,ans,s[110];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a),s[i]=s[i-1]+(a==0);
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				ans+=s[j]-s[i-1]+j-i+1;
		printf("%d\n",ans);ans=0;
	}
}