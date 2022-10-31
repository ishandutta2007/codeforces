#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{	
	int n,k;
	int a[5000],b[5000];
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=k;i++)cin>>b[i];
	sort(b+1,b+k+1);
	int head=k;
	for(int i=1;i<=n;i++)
		if (a[i]==0)
		{
			a[i]=b[head];
			head--;
		}
	int shit=0;
	for(int i=1;i<n;i++)
		if (a[i]>=a[i+1])shit=1;
	if (!shit)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}