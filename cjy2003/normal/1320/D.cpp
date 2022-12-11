#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sed=1641129,mod=1000000007,inv=620149304;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int po[200020];
void init()
{
	po[0]=1;
	for(int i=1;i<=200000;++i)po[i]=1ll*po[i-1]*sed%mod;
}
int n,q;
char a[200020];
struct data
{
	int has,cnt,len,p,s,jcnt;
	friend data operator + (data a,data b)
	{
		data c;
//		c.len=a.len+b.len;c.cnt=a.cnt+b.cnt;c.jcnt=a.jcnt+b.jcnt;
		c.len=a.len+b.len;
		if(a.cnt+a.jcnt==0)
		{
			c.cnt=b.cnt,c.jcnt=b.jcnt,c.p=0,c.s=b.s,c.has=b.has;
		}
		else if(b.cnt+b.jcnt==0)
		{
			c.cnt=a.cnt,c.jcnt=a.jcnt,c.p=a.p,c.s=0,c.has=1ll*a.has*po[b.len]%mod;
		}
		else if(a.len==a.cnt+a.jcnt&&b.len==b.cnt+b.jcnt)
		{
			c.cnt=c.len-(c.len&1);c.jcnt=c.len-c.cnt;
			c.has=c.s=c.p=c.len&1;
		}
		else if(a.len==a.cnt+a.jcnt)
		{
			if(a.s&&b.p)
			{
				c.cnt=a.cnt+b.cnt+2;c.jcnt=a.jcnt+b.jcnt-2;
				add(a.has,mod-1);
				add(b.has,mod-po[b.len-b.cnt-1]);
				c.has=(1ll*a.has*po[b.len-b.cnt-2]+b.has)%mod;
				c.p=0;c.s=b.s;
			}
			else
			{
				c.cnt=a.cnt+b.cnt;c.jcnt=a.jcnt+b.jcnt;
				c.has=(1ll*a.has*po[b.len-b.cnt]+b.has)%mod;
				c.p=a.jcnt?1:b.p,c.s=b.s;
			}
		}
		else if(b.len==b.cnt+b.jcnt)
		{
			if(a.s&&b.p)
			{
				c.cnt=a.cnt+b.cnt+2;c.jcnt=a.jcnt+b.jcnt-2;
				add(a.has,mod-1);
				add(b.has,mod-1);
				c.has=(1ll*a.has*inv+b.has)%mod;
				c.p=a.p,c.s=0;
			}
			else
			{
				c.cnt=a.cnt+b.cnt;c.jcnt=a.jcnt+b.jcnt;
				c.has=(1ll*a.has*po[b.len-b.cnt]+b.has)%mod;
				c.p=a.p,c.s=b.jcnt?1:a.s;
	//			printf("!!!\n");
			}
		}
		else
		{
			c.s=b.s;c.p=a.p;
			if(a.s&&b.p)
			{
				c.cnt=a.cnt+b.cnt+2;c.jcnt=a.jcnt+b.jcnt-2;
				add(a.has,mod-1);
				add(b.has,mod-po[b.len-b.cnt-1]);
				c.has=(1ll*a.has*po[b.len-b.cnt-2]+b.has)%mod;
			}
			else 
			{
				c.cnt=a.cnt+b.cnt;c.jcnt=a.jcnt+b.jcnt;
				c.has=(1ll*a.has*po[b.len-b.cnt]+b.has)%mod;	
			}
		}
		return c;
	}
	void print()
	{
		printf("%d %d %d %d %d %d\n",has,cnt,jcnt,len,p,s);
	}
}s[800080];
void build(int k,int l,int r)
{
	if(l==r)
	{
		if(a[l]=='1')s[k]=data{1,0,1,1,1,1};
		else s[k]=data{0,0,1,0,0,0};
//		printf("%d %d\n",l,l);
//		s[k].print();
		return ;
	}
	build(k<<1,l,l+r>>1);
	build(k<<1|1,(l+r>>1)+1,r);
//	printf("%d %d\n",l,r);
	s[k]=s[k<<1]+s[k<<1|1];
//	s[k].print();
}
data get(int k,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)return s[k];
	if(ll>(l+r>>1))return get(k<<1|1,(l+r>>1)+1,r,ll,rr);
	if(rr<=(l+r>>1))return get(k<<1,l,l+r>>1,ll,rr);
//	printf("%d %d:",max(l,ll),min(r,rr));
	data cur=get(k<<1,l,l+r>>1,ll,rr)+get(k<<1|1,(l+r>>1)+1,r,ll,rr);
//	cur.print();
	return cur;
}
int main()
{
//	printf("%d\n",kpow(sed,mod-2));
	init();
	scanf("%d",&n);
	scanf("%s",a+1);
	build(1,1,n);
//	for(int i=1;i<=n;++i)
//	{
//		for(int j=i+1;j<=n;++j)printf("%d %d:",i,j),get(1,1,n,i,j).print();
//	}
//	return 0;
	scanf("%d",&q);
	int x,y,len;
	while(q--)
	{
		scanf("%d %d %d",&x,&y,&len);
		data s1=get(1,1,n,x,x+len-1);
		data s2=get(1,1,n,y,y+len-1);
//		s1.print();s2.print();
		if(s1.cnt==s2.cnt&&s1.jcnt==s2.jcnt&&s1.has==s2.has)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}