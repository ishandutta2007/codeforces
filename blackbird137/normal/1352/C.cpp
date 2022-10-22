#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define LL long long

using namespace std;

LL read()
{
	LL ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

LL t,n,k,ans,l,r;

int main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();
		if(k<n)
			printf("%lld\n",k);
		else
		{
			l=1,r=1e18;
			while(l<=r)
			{
				LL mid=l+r>>1;
				if(mid-mid/n>=k)
				{
					ans=mid;
					r=mid-1;
				}
				else
					l=mid+1;
			}
			printf("%lld\n",ans);	
		}
		
	}
	return 0;
}