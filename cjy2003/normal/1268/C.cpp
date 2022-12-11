#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,p[200020],nxt[200020],pre[200020],ed1,st2,pos[200020],cnt1,cnt2;
long long sum1,sum2,ans[200020],cur;
namespace BIT
{
	int sum[200020];
	inline void add(int p,int w){while(p<=n)sum[p]+=w,p+=p&-p;}
	inline int query(int p){int s=0;while(p)s+=sum[p],p-=p&-p;return s;}
}
long long calc(int l,int r)
{
	return 1ll*(l+r)*(r-l+1)/2;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]),pos[p[i]]=i,nxt[i]=i+1,pre[i]=i-1;nxt[0]=1,pre[n+1]=n;
	for(int i=1;i<=n;++i)
	{
		cur+=BIT::query(n)-BIT::query(pos[i]);
		BIT::add(pos[i],1);
	}
	cnt1=n/2,cnt2=n-cnt1;
	ed1=n/2,st2=n/2+1;
	for(int i=1;i<=cnt1;++i)sum1+=i;
	for(int i=cnt1+1;i<=n;++i)sum2+=i;
	for(int i=n;i;--i)
	{
	//	printf("%lld\n",cur);
		int c=st2-cnt1-1;
	//	printf("%d %d\n",i,c);
		ans[i]=1ll*cnt1*c-sum1+calc(1,cnt1)+sum2-calc(cnt1+1,i)-1ll*cnt2*c+cur;
		if(pos[i]==st2)sum2-=pos[i],--cnt2,st2=nxt[st2];
		else if(pos[i]<st2)sum1-=pos[i],--cnt1;
		else sum2-=pos[i],--cnt2;
		pre[nxt[pos[i]]]=pre[pos[i]];
		nxt[pre[pos[i]]]=nxt[pos[i]];
		if(cnt1>cnt2)st2=pre[st2],sum2+=st2,sum1-=st2,++cnt2,--cnt1;
		if(cnt2>=cnt1+2)sum2-=st2,sum1+=st2,--cnt2,++cnt1,st2=nxt[st2];
		BIT::add(pos[i],-1);
		cur-=BIT::query(n)-BIT::query(pos[i]);
	}
	for(int i=1;i<=n;++i)printf("%lld ",ans[i]);
	return 0;
}