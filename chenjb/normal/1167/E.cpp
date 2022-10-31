#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define rep(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n;i>=1;i--)
using namespace std;
int n,m;
int l[1100000],r[1100000],pre[1100000],suf[1100000];
int main()
{
	cin>>n>>m;
	rep(i,n)
	{
		int x;
		scanf("%d",&x);
		if (l[x]==0)l[x]=i;
		r[x]=i;
	}
	pre[0]=0; suf[m+1]=n+1;
	rep(i,m)if(!l[i])pre[i]=pre[i-1];else if(l[i]>=pre[i-1])pre[i]=max(pre[i-1],r[i]); else pre[i]=n+1;
	per(i,m)if(!r[i])suf[i]=suf[i+1];else if(r[i]<=suf[i+1]|| !r[i])suf[i]=min(suf[i+1],l[i]);else suf[i]=0;
	if (pre[m]!=n+1){ cout<<1ll*m*(m+1)/2<<endl; return 0; }

	int tail=1;
	long long ans=0;
	for(int i=0;i<=m;i++)
	{
		while (tail<=m && suf[tail]<=pre[i])tail++;
		//cout<<i<<" "<<tail<<endl;
		//cout<<i<<" "<<tail<<endl;
		if (pre[i]!=n+1){ ans=ans+m-tail+2; }
	}
	cout<<ans<<endl;
	return 0;
}