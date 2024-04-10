#include <bits/stdc++.h>

using namespace std;

int n,x;
int h[101];
int rj;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>x;
	rj=x;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		if (h[i]==x) ++rj;
		if (h[i]<x) --rj;
	}
	cout<<rj<<endl;
}