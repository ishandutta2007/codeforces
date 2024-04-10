#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node{ long long sdt,end; }p1[1000003],p2[1000003];
signed main()
{
	int T=read();
	while(T--)
	{
		long long n=read(),k=read(),l1=read(),r1=read(),l2=read(),r2=read();
		if(l1>l2) swap(l1,l2),swap(r1,r2);
		if(r2<r1) l2+=r1-r2,r2+=r1-r2;
	    for(int i=1; i<=n; i++) p1[i].sdt=l1,p1[i].end=r1,p2[i].sdt=l2,p2[i].end=r2;
	    long long ans=10000000000000000LL,res=0,sum=0;
		if(sum<k)
	    {
	      	long long now=0;
	      	if(l2<r1) now=r1-l2;
	      	if(now>0)
	      	{
	      	    sum+=n*now;
	        	for(int i=1; i<=n; i++) p1[i].end-=now,p2[i].end-=now;
	        }
	    }
    	if(sum<k)
    	{
		    for(int i=1; i<=n; i++)
		    {
		        if(sum>=k) break;
		        long long now=p2[i].sdt-p1[i].end;
		        res+=now;
		        if(sum+p2[i].end-p1[i].sdt>=k) res+=k-sum,sum=k;
		        else sum+=p2[i].end-p1[i].sdt,res+=p2[i].end-p1[i].sdt,ans=min(ans,res+2*(k-sum));
      		}
    	}
    	if(sum<k) res+=2*(k-sum);
    	ans=min(ans,res);
    	printf("%lld\n",ans);
	}
    return 0;
}