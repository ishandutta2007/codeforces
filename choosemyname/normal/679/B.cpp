#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
long long a[100010],c[100010],d[100010];
int b[100010];
int main()
{
	for(int i=1;i<=100000;i++)
	{
		a[i]=i*1ll*i*1ll*i;
		if(i>1)
		{
			long long x=a[i]-1;
			while(x)
			{
				//cout<<x<<'s'<<endl;
				int l=1,r=i-1;
				while(l!=r)
				{
					int mid=(l+r+1)>>1;
					if(x>=a[mid])
						l=mid;
					else
						r=mid-1;
				}
				if(b[r]+x/a[r]-1+d[i]>=b[i])
				{
					b[i]=b[r]+x/a[r]-1+d[i];
				//	cout<<b[i]<<endl;
					c[i]=a[i]-1-x%a[r]-a[r]+c[r];
				//	cout<<a[i]<<' '<<c[i]<<endl;
				}
				d[i]+=x/a[r];
				x%=a[r];
			}
		}
		if(b[i]<=d[i])
		{
			b[i]=d[i];
			c[i]=a[i]-1;
		}
		//if(i<=10)
		//	cout<<b[i]<<' '<<c[i]<<endl;
	//	cout<<endl;
	}
	long long x;
	cin>>x;
	long long y=x;
	long long ans=0,nowp=0,now=0;
	for(int i=100000;i>=2;i--)
	{
		if(y>=a[i])
		{
		//	cout<<i<<' '<<'s';
			if(b[i]+y/a[i]-1+now>=ans)
			{
				ans=b[i]+y/a[i]-1+now;
			//	cout<<b[i]<<endl;
				nowp=x-y%a[i]-a[i]+c[i];
			//	cout<<a[i]<<' '<<c[i]<<endl;
			}
			now+=y/a[i];
			y%=a[i];
		}
	}
	int k=0;
	y=x;
	for(int i=100000;i>=1;i--)
	{
		k+=y/a[i];
		y%=a[i];
	}
	if(k>=ans)
	{
		ans=k;
		nowp=x;
	}
	cout<<ans<<' '<<nowp<<endl;
}