#include <bits/stdc++.h>

using namespace std;

int da,uz,n,k;
int h[10001];

int main()
{
	cin>>n>>k;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		uz+=h[i];
		da+=min(uz,8);
		uz-=min(uz,8);
		if (da>=k)
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}