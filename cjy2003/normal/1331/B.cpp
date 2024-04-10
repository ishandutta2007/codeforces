#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,su[1010],sunum;
bool bj[1010];
int main()
{
	for(int i=2;i<=1000;++i)
	{
		if(!bj[i])su[++sunum]=i;
		for(int j=1;j<=sunum&&su[j]*i<=1000;++j)
		{
			bj[su[j]*i]=1;
			if(i%su[j]==0)break;
		}
	}
	scanf("%d",&n);
	for(int i=2;i*i<=n;++i)
		if(n%i==0&&!bj[i]&&!bj[n/i])
		{
			printf("%d%d",i,n/i);
			return 0;
		}
	return 0;
}