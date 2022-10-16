#include<bits/stdc++.h>  
using namespace std;    
int cmp(int a,int b)
{
	return a>b;
}
int main()  
{
	int n,tot=0,ans=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i],tot+=a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
		if((a[i]+ans)*2>tot)
			{cout<<i+1;return 0;}
		else
			ans+=a[i];
}