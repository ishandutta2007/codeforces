#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,x,y;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		x--;
		if(x>=1)a[x-1]+=(y-1);
		if(x<=n-2)a[x+1]+=(a[x]-y);
		a[x]=0;
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
}