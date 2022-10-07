#include<bits/stdc++.h>
using namespace std;
int n,f[100005],i,j,ans=1,vis[100005],cur,x,s;
int main()
{
	scanf("%d",&n);
	for(i=2;i*i<=n;++i)
		if(!f[i])
			for(j=i*2;j<=n;j+=i)
				f[j]=1;
	for(i=n;i>=400;--i)
	{
		if(!f[i])
		{
			for(j=i;j<=n;j+=i)
				if(!vis[j])
				{
					vis[j]=1;
					++cur;
				}
			cout<<'B'<<' '<<i<<endl;
			scanf("%d",&x);
		}
		if((i-400)%500==0)
		{
			cout<<'A'<<' '<<1<<endl;
			scanf("%d",&x);
			if(x!=n-cur)
			{
				for(j=i;j<i+500&&j<=n;++j)
					if(!f[j])
					{
						cout<<'A'<<' '<<j<<endl;
						scanf("%d",&x);
						if(x)
						{
							ans*=j;
							break;
						}
					}
				if(ans!=1)
					break;
			}
		}
	}
	for(i=min(400,n);i>=2;--i)
		if(!f[i])
		{
			if(ans*i>n)
				continue; 
			cout<<'B'<<' '<<ans*i<<endl;
			scanf("%d",&x);
			while(ans*i<=n)
			{
				cout<<'A'<<' '<<ans*i<<endl;
				scanf("%d",&x);
				if(x!=0)
					ans*=i;
				else
					break;
			}
		}
	cout<<'C'<<' '<<ans<<endl;
}