#include<bits/stdc++.h>
#include<iostream> 
using namespace std;
long long n,s1,s2,x,y,ans,it,a[200003];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	while(it<n)
	{
		ans++;
		s1=0,s2=0;
		while(it<n&&a[it]==-1) 
		{
			s1++;
			it++;
		}
		if(it==n)
		    break;
		x=a[it];  
		it++;
		while(it<n&&a[it]==-1)
		{
			s2++;
			it++;
		}
		if(it==n)
		    break;
		y=a[it]; 
		if((y-x)%(s2+1)!=0)
		    continue;
		int d=(y-x)/(s2+1); 
		if(x-s1*d<=0)
		    continue;
		it++;
		while(it<n)
			if(a[it]==-1)
			{
				if(a[it-1]+d<=0) 
					break;
				a[it]=a[it-1]+d; 
				it++;
			}
			else
			{
				if(a[it]!=a[it-1]+d)
					break;
				it++;
			}
	}
	cout<<ans;
	return 0;
}