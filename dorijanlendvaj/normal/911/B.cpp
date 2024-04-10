#include <bits/stdc++.h>

using namespace std;

int n,a,b,rj;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>a>>b;
	for (int i=1;i<n;++i)
	{
		int j=n-i;
		rj=max(rj,min(a/i,b/j));
	}
	cout<<rj<<endl;
}