#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector> 
#define ll long long
#define MN 100000
using namespace std;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ll d,t[MN+5],per,ans=0,n,a,m,last=0;

int main()
{
	n=read();m=read();a=read();d=read();per=d/a+1;
	for(int i=1;i<=m;++i) t[i]=read();t[++m]=1LL*n*a;
	sort(t+1,t+m+1);
	for(int i=1,j;i<=m;i=j)
	{
		ll l=last/a+1;
		if(l<=n)
		{
			ll r=min((ll)n,t[i]/a);
			if(l<=r)
			{
				ll tms=(r-l+per)/per;ans+=tms;
				ll lastget=l*a+(tms-1)*per*a+d;
			//	cout<<i<<" "<<last<<" "<<l<<" "<<r<<" "<<lastget<<" "<<tms<<endl;
				if(t[i]<=lastget)
				{
					for(j=i;j<=m&&t[j]<=lastget;) ++j;
					last=lastget;
					continue;	
				}	
			}
		}	
		last=t[i]+d;++ans;
		for(j=i;j<=m&&t[j]<=last;) ++j;
	}
	printf("%lld\n",ans);
	return 0;
}