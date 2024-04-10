#include<iostream>
#include<cstring>
using namespace std;
bool h[256];
char a[100005];
int main()
{
	int n;
	cin>>n;
	int i;
	cin>>a;
	if(n==1)
	{
		cout<<"Yes";
		return 0;
	}
	for(i=0;i<n;i++)
	{
		if(h[a[i]]==1) 
		{
			cout<<"Yes";
			return 0;
		}
		h[a[i]]=1;
	}
	cout<<"No";
	return 0;
}