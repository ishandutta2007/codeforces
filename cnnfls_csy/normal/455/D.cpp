#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<deque>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,b=360,l,r,k,ans,num[100005],op,cnt[365][100005];
deque<int> dq[365];
int main()
{
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		dq[i/b].push_back(num[i]);
		cnt[i/b][num[i]]++;
	}
	scanf("%d",&m);
	while (m--)
	{
		scanf("%d%d%d",&op,&l,&r);
		l=(l+ans-1)%n;
		r=(r+ans-1)%n;
		if (l>r) swap(l,r);
		if (op==1)
		{
			if (l/b==r/b)
			{
				int mem=dq[l/b][r%b];
				dq[l/b].erase(dq[l/b].begin()+r%b);
				dq[l/b].insert(dq[l/b].begin()+l%b,mem);
			}
			else
			{
				int mem=dq[r/b][r%b];
				dq[r/b].erase(dq[r/b].begin()+r%b);
				cnt[r/b][mem]--;
				dq[l/b].insert(dq[l/b].begin()+l%b,mem);
				cnt[l/b][mem]++;
				for (i=l/b;i<r/b;i++)
				{
					int mem2=dq[i].back();
					dq[i].pop_back();
					cnt[i][mem2]--;
					dq[i+1].push_front(mem2);
					cnt[i+1][mem2]++;
				}
			}
		}
		if (op==2)
		{
			scanf("%d",&k);
			k=(k+ans-1)%n+1;
			ans=0;
			if (l/b==r/b)
			{
				for (i=l%b;i<=r%b;i++) ans+=(dq[l/b][i]==k);
			}
			else
			{
				for (i=l/b+1;i<r/b;i++)
				{
					ans+=cnt[i][k];
				}
				for (i=l%b;i<dq[i/b].size();i++)
				{
					ans+=(dq[l/b][i]==k);
				}
				for (i=0;i<=r%b;i++)
				{
					ans+=(dq[r/b][i]==k);
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}