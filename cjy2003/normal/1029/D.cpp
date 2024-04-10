#pragma GCC optimize("O3")
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
map<int,int>m[11];
int n,w[200001];
long long a[200001],tm[11],p,x,ans;
int main()
{
	scanf("%d %I64d",&n,&p);
	for(int i=1;i<=n;++i)
	{
		scanf("%I64d",&a[i]);
		x=a[i];
		while(x)
		{
			x/=10;
			++w[i];	
		}
		++m[w[i]][a[i]%p];	
		a[i]%=p;
	}
	tm[0]=1;
	for(int i=1;i<=10;++i)
		tm[i]=tm[i-1]*10%p;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=10;++j)
			ans+=m[j][(p-a[i]*tm[j]%p)%p];
		if((a[i]+tm[w[i]]*a[i]%p)%p==0)--ans;	
	}
	printf("%I64d",ans);
	return 0;
}