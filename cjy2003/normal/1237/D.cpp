#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[300030],w[300030],st[300030],tp,ans[300030];
int find(int x)
{
	if(!tp||x<=2*w[1])return 3*n+1;
	int p=lower_bound(w+1,w+1+tp,(x+1)/2)-w-1;
	return st[p];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i+n]=a[i+2*n]=a[i];
	ans[3*n+1]=3*n+1;
	for(int i=3*n;i;--i)
	{
		int p=find(a[i]);
	//	printf("%d ",p);
		ans[i]=min(ans[i+1],p);
		while(tp&&a[i]<=w[tp])--tp;
		st[++tp]=i;w[tp]=a[i];
	}
//	for(int i=1;i<=3*n;++i)printf("%d ",ans[i]);printf("\n");
	for(int i=1;i<=n;++i)
		if(ans[i]==3*n+1)printf("-1 ");
		else printf("%d ",ans[i]-i);
	return 0;
}