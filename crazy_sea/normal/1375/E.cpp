#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e3+10;
int n,a[N],p[N],len,ans;
bool cmp(int x,int y)
{
	return a[x]==a[y]?x<y:a[x]<a[y];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),p[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans+=a[j]<a[i];
	printf("%d\n",ans);
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<n;j++)
			if(p[j]>p[j+1])
				swap(p[j],p[j+1]),printf("%d %d\n",p[j],p[j+1]);
}