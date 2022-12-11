#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100010],b[100010],pos[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),pos[a[i]]=i;
	for(int i=1;i<=n;++i)scanf("%d",&b[i]),b[i]=pos[b[i]];
	int mi=0x3f3f3f3f,ans=0;
	for(int i=n;i;--i)
	{
		if(b[i]>mi)++ans;
		else mi=b[i];
	}
	printf("%d",ans);
	return 0;
}