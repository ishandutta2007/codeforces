#include<iostream>
#include<cstring>
using namespace std;
int a[100000],n,k;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if (k<=i) break;
		k-=i;
	}	
	cout<<a[k]<<endl;
}