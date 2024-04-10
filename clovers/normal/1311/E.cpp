#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,t;
int d[N],f[N],v[N];

int main()
{
	cin>>t;
	while(t--)
	{
		int dep=-1,sum=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			if((i&(-i))==i) 
			{
				dep++;
				v[dep+1]=i;
			}
			d[i]=dep;
			f[i]=i/2;
			sum+=dep;
		}
		//for(int i=1;i<=n;i++) cout<<d[i]<<endl;
		if(sum>m||n*(n-1)/2<m)
		{
			puts("NO");
			continue;
		}
		int i=n,now=d[n];
		while(i)
		{
			if((i&(-i))==i) 
			{
				i--;
				continue;
			}
			if(sum+now+1-d[i]>=m) break;
			sum+=now+1-d[i];
			now++;
			v[now+1]=i;
			f[i]=v[now]; d[i]=now;
			i--;
		}
		if(sum<m)
		{
			while((i&(-i))==i) i--;
			int del=m-sum;
			int Dep=d[i]+del;
			f[i]=v[Dep];
		}
		puts("YES");
		for(i=2;i<=n;i++) printf("%d ",f[i]); puts("");
	}
}