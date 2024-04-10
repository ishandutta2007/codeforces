#include <bits/stdc++.h>

using namespace std;

int n;
int h[10001];
int ma,sol;

int main()
{
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		ma=max(h[i],ma);
	}
	for (int i=0;i<n;++i)
	{
		sol+=ma-h[i];
	}
	cout<<sol<<endl;
}