#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100010];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n-1;i++)
	{
		if(a[0]>a[i]&&a[i]<a[i+1] || a[0]<a[i] &&a[i]>a[i+1])
		{
			cout<<3<<endl;
			printf("1 %d %d",i+1,i+2);
			exit(0); 
		}
	}
	cout<<0<<endl;
	return 0;
}