#include <bits/stdc++.h>
using namespace std;
const int maxn=200;
int r,g,b,red[maxn+1],green[maxn+1],blue[maxn+1];
long long ans,f[maxn+1][maxn+1][maxn+1];
int main()
{
	scanf("%d%d%d",&r,&g,&b);
	for(int i=1;i<=r;++i)
		scanf("%d",&red[i]);
	for(int i=1;i<=g;++i)
		scanf("%d",&green[i]);
	for(int i=1;i<=b;++i)
		scanf("%d",&blue[i]);
	sort(red+1,red+r+1,greater<int>());
	sort(green+1,green+g+1,greater<int>());
	sort(blue+1,blue+b+1,greater<int>());
	for(int i=0;i<=r;++i)
		for(int j=0;j<=g;++j)
			for(int k=0;k<=b;++k)
				ans=max(ans,f[i][j][k]=max(i&&j?f[i-1][j-1][k]+red[i]*green[j]:0,max(i&&k?f[i-1][j][k-1]+red[i]*blue[k]:0,j&&k?f[i][j-1][k-1]+green[j]*blue[k]:0)));
	printf("%lld",ans);
	return 0;
}