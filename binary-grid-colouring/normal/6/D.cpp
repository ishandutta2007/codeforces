#include<bits/stdc++.h>
using namespace std;
int ans=9999999;
int h[100];
int a,b,n;
vector<int>V;
vector<int>V2;

void dfs(int x,int times)
{
	if(times>=ans)return;
	if(x==n)
	{
		if(h[x]<0){
			V2=V;
			ans=times;
		}
		return ;
	}
	for(int i=0; i <= max( h[x-1]/b+1,max( h[x]/a+1, h[x+1]/b+1) );i++)
	{
		if(h[x-1]<b*i)
		{
			h[x-1] -= b*i;
			h[x] -= a*i;
			h[x+1] -= b*i;
			for(int j=0;j<i;j++) V.push_back(x);
			dfs(x+1,times+i);
			for(int j=0;j<i;j++) V.pop_back();
			h[x-1] += b*i;
			h[x] += a*i;
			h[x+1] += b*i; 
		}
	}
}
int main()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)cin>>h[i];
	dfs(2,0);
	cout<<ans<<endl;
	for(int i=0;i<V2.size();i++)cout<<V2[i]<<" ";
	cout<<endl;
	return 0;
}