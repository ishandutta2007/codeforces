#include<bits/stdc++.h>
using namespace std;
int main()
{
	int xh,n,m;
	long long ans=-2000000000000000000,fin_res=-2000000000000000000;
	cin>>n>>m;
	long long a[n],b[m];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	for(int i=0;i<n;i++)
	{
		long long ans1=-2000000000000000000;
		for(int j=0;j<m;j++)
			ans1=max(ans1,a[i]*b[j]);
		if(ans<ans1)
			xh=i,
			ans=ans1;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(i-xh)
				fin_res=max(fin_res,a[i]*b[j]);
	cout<<fin_res;
}