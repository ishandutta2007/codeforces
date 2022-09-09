#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,x,y,ans=3;
map<int,int> mp;
int main()
{
	scanf("%d%d",&n,&x);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&y);
		if (mp.count(y)) ans=min(ans,mp[y]);
		if (mp.count(x&y)&&(x&y)!=y) ans=min(ans,1+mp[x&y]);
		mp[y]=min(mp[y],0);
		if ((x&y)!=y) if (!mp.count(x&y)) mp[x&y]=1;
	}
	if (ans==3) cout<<-1; else cout<<ans;
}