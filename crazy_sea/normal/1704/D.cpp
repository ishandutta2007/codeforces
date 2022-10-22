#include<cstdio>
using namespace std;
const int N=1e6+10;
unsigned long long s[N],a;
int n,m,T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			s[i]=0;
			for(int j=1;j<=m;j++)
				scanf("%llu",&a),s[i]=s[i]+a*j;
		}
		if(s[1]!=s[2])
		{
			if(s[1]!=s[3]) printf("1 %llu\n",s[1]-s[2]);
			else printf("2 %llu\n",s[2]-s[1]);
		}
		else for(int i=3;i<=n;i++)
			if(s[i]!=s[1]) printf("%d %llu\n",i,s[i]-s[1]);
	}
}