#include<bits/stdc++.h>
using namespace std;
int n,i,a[500005],ans[500005];
struct str{
	int a,x;
}b[500005];
bool cmp(str a,str b)
{
	return a.a<b.a;
}
int main(){
    scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		b[i].a=a[i]+a[i%n+1];
		b[i].x=i;
	}
	sort(b+1,b+1+n,cmp);
	for(i=1;i<=n;i++)
		ans[b[i].x]=i-1;
	for(i=1;i<=n;i++)
		printf("%d ",ans[i]);
}