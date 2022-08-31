#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define fz1(i,n) for (i=1;i<=n;i++)
#define fd1(i,n) for (i=n;i>=1;i--)
#define fz0g(i,n) for (i=0;i<=n;i++)
#define fd0g(i,n) for (i=n;i>=0;i--)
#define fz0k(i,n) for (i=0;i<n;i++)
#define fd0k(i,n) for (i=(long long)(n-1);i>=0;i--)
#define fz(i,x,y) for (i=x;i<=y;i++)
#define fd(i,y,x) for (i=y;i>=x;i--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,ll,rr,mid,s1,s2;
double px,py,l[400005],r[400005],cnt[400005],sy,sl,sr,pw,ans,p1,p2;
int main()
{
	scanf("%lf%lf%lf",&sy,&sl,&sr);
	scanf("%d",&n);
	l[1]=0;r[n*2+1]=1e10;
	fz1(i,n)
	{
		scanf("%lf%lf",&l[i*2],&r[i*2]);
		r[i*2-1]=l[i*2];
		l[i*2+1]=r[i*2];
		cnt[i*2-1]=cnt[i*2-2];
		cnt[i*2]=cnt[i*2-1]+r[i*2]-l[i*2];
	}
	cnt[n*2+1]=cnt[n*2];
	scanf("%d",&m);
	while (m--)
	{
		scanf("%lf%lf",&px,&py);
		pw=(py-sy)/py;
		/*ll=0;rr=n;s1=n+1;
		while (ll<rr)
		{
			mid=(ll+rr+1)/2;
			if ((l[mid]-px)*pw+px>=sl)
			{
				s1=mid;
				rr=mid-1;
			}
			else ll=mid;
		}
		s2=0;ll=1;rr=n+1;
		while (ll<rr)
		{
			mid=(ll+rr)/2;
			if ((r[mid]-px)*pw+px<=sr)
			{
				s2=mid;
				ll=mid+1;
			}
			else rr=mid;
		}*/
		p1=(sl-px)/pw+px;
		p2=(sr-px)/pw+px;
		s1=lower_bound(l+1,l+n*2+2,p1)-l;
		s2=upper_bound(r+1,r+n*2+2,p2)-r;
		if (s1-1>s2)
		{
			puts("0.0000000");
			continue;
		}
		if (s1-1==s2)
		{
			printf("%.20f\n",((s2)%2==0)*(sr-sl));
			continue;
		}
		ans=0;
		if ((s1-1)%2==0&&s1>1&&(r[s1-1]-px)*pw+px>=sl) ans+=(r[s1-1]-px)*pw+px-sl;
		if ((s2)%2==0&&s2<n*2+1&&(l[s2]-px)*pw+px<=sr) ans+=sr-((l[s2]-px)*pw+px);
		if (s2-1>=s1) ans+=(cnt[s2-1]-cnt[s1-1])*pw;
		printf("%.20f\n",ans);
	}
	return 0;
}