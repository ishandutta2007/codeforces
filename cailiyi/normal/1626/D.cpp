#include<bits/stdc++.h>
#define N 200000
using namespace std;
int T,n,a[N+5],up[N+5],ans;
vector<int> v;
int main()
{
	up[0]=1;
	for(int i=1;i<=N;++i)
		up[i]=up[i>>1]<<1;
	for(int i=0;(1<<i)<=N;++i) up[1<<i]>>=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n),ans=1e9;
		v.clear();
		for(int i=1;i<=n;++i) scanf("%d",a+i);
		sort(a+1,a+1+n);
		for(int i=0,last=0;i<=n;++i)
			if(a[i]!=a[i+1])
			{
				if(up[last]!=up[i]) v.push_back(last);
				int minn=1e9;last=i;
				for(int x:v) minn=min(minn,up[x]+up[i-x]);
				ans=min(ans,minn+up[n-i]);
				ans=min(ans,up[i]+up[n-i]+1);
			}
		printf("%d\n",ans-n);
	}
	return 0;
}