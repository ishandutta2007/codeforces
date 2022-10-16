#include<bits/stdc++.h>
using namespace std;
int T,n,a[503];
bool b[503];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<int>v[2];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int awsl=0;
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			awsl|=(1<<b[i]);
		}
		if(awsl==3)
		{
			cout<<"Yes\n";
			continue;
		}
		bool ok=1;
		for(int i=1;i<n;i++)
			if(a[i-1]>a[i])
				ok=0;
		if(ok)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}