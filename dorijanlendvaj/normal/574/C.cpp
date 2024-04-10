#include <bits/stdc++.h>

using namespace std;

int n;
int h[100001];

int main()
{
	cin>>n;
	for (int i=0;i<n;++i) cin>>h[i];
	for (int i=0;i<n;++i)
	{
		while (h[i]%2==0) h[i]/=2;
		while (h[i]%3==0) h[i]/=3;
	}
	for (int i=0;i<n;++i)
	{
		if (h[i]!=h[0])
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
}