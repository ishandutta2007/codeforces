#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main()
{
	int n,k;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		a[k] = 1;
	}
	for(int i=1;i<=10010;i++)
	{
		if(a[i]==0)
		{
			cout<<i<<endl;
			break;
		}
	}
	return 0;	
}