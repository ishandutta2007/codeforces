#include<bits/stdc++.h>
using namespace std;
int n,a[303],x,it=1,w[303];
bool u[303];
string s[303];
void dfs(int sum)
{
	if(!u[a[sum]])x=min(x,a[sum]);
	w[sum]=it;
	for(int i=0;i<n;i++)
		if(s[sum][i]=='1'&&w[i]!=it)
			dfs(i);
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
	{
		x=n;
		dfs(i);
		u[x]=1;
		cout<<x<<' ';
		it++;
	}
}