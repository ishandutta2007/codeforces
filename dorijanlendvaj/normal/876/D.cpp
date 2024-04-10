#include <bits/stdc++.h>

using namespace std;

int n,mpos,a,rj;
bool un[300010];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	cout<<1<<' ';
	mpos=n;
	rj=1;
	for (int i=0;i<n;++i)
	{
		cin>>a;
		++rj;
		un[a]=true;
		while (un[mpos])
		{
			--mpos;
			--rj;
		}
		cout<<rj<<' ';
	}
}