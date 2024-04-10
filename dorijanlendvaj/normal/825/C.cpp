#include <bits/stdc++.h>

using namespace std;

int rj,n,k;
int h[1001];

int main()
{
	std::cin.sync_with_stdio(false);
	cin>>n>>k;
	k*=2;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
	}
	sort(h,h+n);
	for (int i=0;i<n;++i)
	{
		while (h[i]>k)
		{
			++rj;
			k*=2;
		}
		k=max(k,h[i]*2);
	}
	cout<<rj<<endl;
}