#include<cstdio>
#include<algorithm>
using namespace std;

int n,w[300010];
int ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",w+i);
	int hd=1;
	while (w[hd+1]==w[1]) hd++;
	for (int i=hd+1;i<=n;i++)
	{
		if (w[i]==w[1]) ans=max(ans,i-hd-1);
		else ans=max(ans,i-1);
	}
	printf("%d\n",ans);
	return 0;
}