#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,num[100005],ind[100005],used[100005],x;
vector<vector<int>/**/>ans;
vector<int> now;
bool cmp(int x,int y)
{
	return num[x]<num[y];
} 
int main()
{
	ios::sync_with_stdio(0); 
	cin>>n;
	for (i=1;i<=n;i++) cin>>num[i]; 
	for (i=1;i<=n;i++) ind[i]=i;
	sort(ind+1,ind+n+1,cmp);
	for (i=1;i<=n;i++)
	{
		now.clear();
		if (!used[i])
		{
			x=i;
			while (!used[ind[x]])
			{
			 	x=ind[x];
			 	now.push_back(x);
			 	used[x]=1;
			}
			ans.push_back(now);
		}
	}
	cout<<ans.size()<<endl;
	for (i=0;i<ans.size();i++)
	{
		cout<<ans[i].size();
		for (j=0;j<ans[i].size();j++) cout<<' '<<ans[i][j];
		cout<<endl;
	}
	return 0;
}