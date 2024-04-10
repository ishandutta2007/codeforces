#include<bits/stdc++.h>
using namespace std;
int i,i0,n,m,ans,a[400005];
set<int>s;
map<int,int>mp;
int main()
{
    scanf("%d %d",&n,&m);
	m*=8;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int ans=INT_MAX;
	for(i=i0=1;i<=n;i++)
	{
		mp[a[i]]++;
		if(mp[a[i]]==1)s.insert(a[i]);
		while((int)ceil(log2(s.size()))*n>m)
		{
			mp[a[i0]]--;
			if(mp[a[i0]]==0)s.erase(a[i0]);
			i0++;
		}
		ans=min(ans,n-i+i0-1);
	}
	printf("%d\n",ans);
    return 0;
}