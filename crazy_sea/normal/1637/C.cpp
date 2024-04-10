#include<cstdio>
using namespace std;
int n,T,a[100010],s,w1,w2,p;
long long ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=w1=w2=s=p=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=2;i<n;i++)
		{
			if(a[i]>1) p++,w1=i;
			ans+=a[i]/2;
			a[i]&=1;
			if(a[i]) w2=i;
			s+=a[i];
		}
		if(p==0) printf("%d\n",s?-1:0);
		else if(p==1)
		{
			if(s==0||s>1) printf("%lld\n",ans+s);
			else printf("%lld\n",w1==w2?-1:ans+1);
		}
		else printf("%lld\n",ans+s);
	}
}