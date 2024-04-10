#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[110],ans;
bool bj[110];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
	{
		if(!bj[i])
		{
			++ans;
			for(int j=i;j<=n;++j)
				if(a[j]%a[i]==0)bj[j]=1;
		}
	}
	printf("%d",ans);
	return 0;
}