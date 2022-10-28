#include<bits/stdc++.h>
using namespace std ;
int main()
{
	int n;cin>>n;int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int sum=0,count=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(sum<0)
		{
			while(a[i]==-1 && i<n){i++;count++;}
			sum=0;i--;
		}
	}
	cout<<count;
	return 0;
}