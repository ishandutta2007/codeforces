#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k,p[100010];
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&p[i]);
	int ans=p[n]-p[1]+1;
	for(int i=1;i<n;++i)
		p[i]=p[i+1]-p[i]-1;
	sort(p+1,p+n);
	for(int i=1;i<k;++i)
		ans-=p[n-i];
	printf("%d",ans);
	return 0;
}