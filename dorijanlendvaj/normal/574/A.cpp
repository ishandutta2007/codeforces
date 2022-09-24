#include <bits/stdc++.h>

using namespace std;

int n;
int h[101];
int brojac;

int maxi()
{
	int r=0;
	for (int i=1;i<n;++i)
	{
		r=max(r,h[i]);
	}
	return r;
}

int wmaxi()
{
	int r=0;
	int ir=0;
	for (int i=1;i<n;++i)
	{
		if (h[i]>r) ir=i;
		r=max(r,h[i]);
	}
	return ir;
}

int main()
{
	cin>>n;
	for (int i=0;i<n;++i) cin>>h[i];
	while (h[0]<=maxi())
	{
		--h[wmaxi()];
		++h[0];
		++brojac;
	}
	cout<<brojac<<endl;
}