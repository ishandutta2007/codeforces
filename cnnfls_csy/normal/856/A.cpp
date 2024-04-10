#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
#define sqr(x) (x)*(x)
using namespace std;
int t,n,m,i,j,num[105],now;
bool used[1000005];
vector<int> ans;
int main()
{
	ios::sync_with_stdio(0); 
	cin>>t;
	while (t--)
	{
		cin>>n;
		vector<int> cha,ncha;
		memset(used,0,sizeof(used));
		for (i=1;i<=n;i++)
		{
			cin>>num[i];
		}
		sort(num+1,num+n+1);
		bool same=0;
		for (i=1;i<n;i++)
		{
			if (num[i]==num[i+1])
			{
				same=1;
				break;
			}
		}
		if (same)
		{
			cout<<"NO"<<endl;
			continue;
		}
		for (i=1;i<=n;i++)
		{
			for (j=i+1;j<=n;j++)
			{
				ncha.push_back(num[j]-num[i]);
			}
		}
		sort(ncha.begin(),ncha.end());
		if (!ncha.empty())
		{
			cha.push_back(ncha[0]);
		}
		for (i=1;i<ncha.size();i++)
		{
			if (ncha[i]!=ncha[i-1])
			{
				cha.push_back(ncha[i]);
			}
		}
		bool ok=1;
		ans.clear();
		now=1;
		for (i=1;i<=n;i++)
		{
			while (used[now]&&now<=1000000) now++;
			if (now>1000000)
			{
				ok=0;
				break;
			}
			used[now]=1;
			for (j=0;j<cha.size();j++)
			{
				if (now+cha[j]>1000000) break;
				used[now+cha[j]]++;
			}
			ans.push_back(now);
		}
		if (!ok)
		{
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		for (i=0;i<ans.size();i++)
		{
			cout<<ans[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}