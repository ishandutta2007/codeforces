#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int l=1,r=n;
	for(int i=0;i<k;i++)
	{
		if(i%2==0)
		{
			cout<<l<<" ";
			l++;
		}
		else {
			cout<<r<<" ";
			r--;
		}
	}
	if((k-1)%2==0)
	{
		for(int i=k;i<n;i++)
		{
			cout<<l<<" ";
			l++;
		}
	}
	else{
		for(int i=k;i<n;i++)
		{
			cout<<r<<" ";
			r--;
		}
	}
	cout<<endl;
}