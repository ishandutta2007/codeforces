#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

int t,l,r,m;

signed main()
{
	t=read();
	while(t--)
	{
		l=read();r=read();m=read();
		for(int a=l;a<=r;++a)
		{
			int t1=m/a;
			int t2=t1+1;
			if(t1!=0&&m-t1*a<=r-l)
			{
				printf("%lld %lld %lld\n",a,l+m-t1*a,l);
				break;
			}
			else if(m-t2*a>=l-r)
			{
				printf("%lld %lld %lld\n",a,l,l+t2*a-m);
				break;
			}
		}
	}
	return 0;
}