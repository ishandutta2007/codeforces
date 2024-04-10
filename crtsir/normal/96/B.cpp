#include<bits/stdc++.h>
using namespace std;
long long n;
vector<long long>v;
void dfs(long long x,int d)
{
	//cout<<x;
	if(x>1e14)return;
	if(x>=n&&!d)v.push_back(x);
	dfs(x*10+4,d+1);
	dfs(x*10+7,d-1);
}
int main()
{
	cin>>n;
	dfs(0,0);
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
		if(v[i]>=n)
		{
			cout<<v[i];
			return 0;
		}
}