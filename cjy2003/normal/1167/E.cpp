#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x,a[1000010],l[1000010],r[1000010];
long long ans;
bool bj[1000010];
int main()
{
	scanf("%d %d",&n,&x);
	for(int i=1;i<=x;++i)l[i]=n+1,r[i]=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		r[a[i]]=max(r[a[i]],i);
		l[a[i]]=min(l[a[i]],i);
		bj[a[i]]=1;
	}
	bj[0]=1;
//	for(int i=1;i<=x;++i)printf("%d %d\n",l[i],r[i]);
	int last=1,mr=r[1],ml=n+1;
	while(last+1<=x&&l[last+1]>mr)
		if(bj[++last])mr=r[last];
		else r[last]=mr;
	for(int i=x;i>=1;--i)
	{
		while((ml<mr&&last)||last>=i)mr=r[--last];
		ans+=last+1;
		if(r[i]>ml&&bj[i])break;
		ml=min(ml,l[i]);
	//	printf("%d %lld\n",i,ans);
	}
	printf("%I64d",ans);
	return 0;
}