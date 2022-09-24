#include <bits/stdc++.h>

using namespace std;

int n,ma,in;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>in;
		ma=max(ma,in);
	}
	cout<<max(0,ma-25)<<endl;
}