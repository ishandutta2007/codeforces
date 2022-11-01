// codeforces.cpp : 
//
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
int x[567],y[567],ans[567];
queue<int>a[200010],c[200010];

int check(int k)
{
	for(int i=0;i<200000;i++) a[i] = c[i];
	for(int i=0;i<n;i++)
	{
		if(abs(i-k)%2==1)
		{
			ans[i] = -1;continue;
		}
		int nx=(i+1)%n;
		int ls = i - 1;
		if(ls==-1)ls = n - 1;
		int sum = abs(y[nx]-y[i])+abs(x[nx]-x[i])
		+abs(y[ls]-y[i])+abs(x[ls]-x[i]);
		if(a[sum].size()==0) return 0;
		ans[i] = a[sum].front()+1;
		a[sum].pop();
	}
	return 1;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<m;i++){
		int l;
		cin>>l;
		c[l].push(i); 
	}
	
	if(check(0))
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
	else if(check(1))
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)cout<<ans[i]<<" ";
		cout<<endl; 
	}
	else
	cout<<"NO"<<endl;
	return 0;
}