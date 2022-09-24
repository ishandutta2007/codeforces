#include <bits/stdc++.h>

using namespace std;

int r;

int main()
{
	int n,s,q;
	cin>>n>>s>>q;
	do
	{
		s*=q;
		++r;
	}
	while (s<n);
	cout<<r<<endl;
}