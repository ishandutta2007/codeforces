#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> >merge(vector<vector<int> >a,vector<vector<int> >b)
{
	vector<vector<int> >ret;
	ret.resize(a.size());
	for(int i=0;i<a.size();i++)for(int j=0;j<a.size();j++)ret[i].push_back(-1000000000);
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<a.size();j++)
		{
			for(int k=0;k<a.size();k++)
			{
				ret[j][k]=max(ret[j][k],a[j][i]+b[i][k]);
			}
		}
	}
	return ret;
}
vector<vector<int> >po(vector<vector<int> >v,int t)
{
	if(t==1)return v;
	vector<vector<int> >z=po(v,t/2);
	z=merge(z,z);
	if(t%2==1)z=merge(z,v);
	return z;
}
int main()
{
	int num,len;
	scanf("%d%d",&num,&len);
	vector<int>vec,zat;
	for(int i=0;i<num;i++)
	{
		int z;
		scanf("%d",&z);
		vec.push_back(z);
		zat.push_back(z);
	}
	sort(zat.begin(),zat.end());
	for(int i=0;i<num;i++)
	{
		vec[i]=lower_bound(zat.begin(),zat.end(),vec[i])-zat.begin();
	}
	vector<vector<int> >m;
	for(int i=0;i<num;i++)
	{
		int dp[100];
		fill(dp,dp+100,-1000000000);
		dp[i]=0;
		for(int j=0;j<num;j++)
		{
			int maxi=-1000000000;
			for(int k=0;k<=vec[j];k++)
			{
				maxi=max(maxi,dp[k]+1);
			}
			dp[vec[j]]=maxi;
		}
		vector<int>zv;
		for(int j=1;j<num;j++)dp[j]=max(dp[j],dp[j-1]);
		for(int j=0;j<num;j++)zv.push_back(dp[j]);
		m.push_back(zv);
	}
	printf("%d\n",po(m,len)[0][num-1]);
}