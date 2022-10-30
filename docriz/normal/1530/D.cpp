#include<bits/stdc++.h>
using namespace std;
int T,n,a[200005],vis[200005],ans[200005],lst,pre;
int siz[200005],k;
vector<int>s;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);k=0;
		for(int i=1;i<=n;i++)vis[i]=siz[i]=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),siz[a[i]]++;
		s.clear();
		lst=pre=0;
		for(int i=1;i<=n;i++)if(siz[i]==0)s.push_back(i);
		for(int i=0;i<s.size();i++)
		{
			int x=s[i];
			if(pre)ans[pre]=x;
			if(!lst)lst=x;
			vis[x]=1;
			while(!vis[a[x]])
			{
				ans[x]=a[x];k++;
				x=a[x];
				vis[x]=1;
			}	
			pre=x;
		}
		if(pre&&lst)ans[pre]=lst;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				vis[i]=1;
				k++;ans[i]=a[i];
				int j;
				for(j=a[i];j!=i;j=a[j])
				{
					vis[j]=1;
					k++;
					ans[j]=a[j];	
				}	
			}	
			
		}	
		printf("%d\n",k);
		for(int i=1;i<n;i++)printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
	}
	return 0;
}