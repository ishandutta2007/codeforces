#include<bits/stdc++.h>
using namespace std;
int n,i,j,t,a[300005],vis[300005];
long long ans;
struct str{
	int s,x;
};
bool operator <(str a,str b)
{
	return a.s>b.s;
}
priority_queue<str> q;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		if(!q.empty())
		{
			str x=q.top();
			q.pop();
			if(x.s<a[i])
			{
				ans+=a[i]-x.s;
				if(vis[x.x]==1)
				{
					q.push(x);
					vis[x.x]=0;
				}
				vis[i]=1;
				q.push((str){a[i],i});
			}
			else
			{
				q.push((str){a[i],i});
				q.push(x);
			}
		}
		else
			q.push((str){a[i],i});
	cout<<ans;
}