#include <bits/stdc++.h>

using namespace std;

int n,k;
int pmi[100001],smi[100001];
int h[100001],ma=-1000100000,mi=1000100000;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		mi=min(mi,h[i]);
		ma=max(ma,h[i]);
	}
	pmi[0]=h[0];
	smi[n-1]=h[n-1];
	for (int i=1;i<n;++i) pmi[i]=min(pmi[i-1],h[i]);
	for (int i=n-2;i>=0;--i) smi[i]=min(smi[i+1],h[i]);
	if (k==1) cout<<mi<<endl;
	else if (k>=3) cout<<ma<<endl;
	else
	{
		ma=-1001001000;
		for (int i=0;i<n-1;++i)
		{
			ma=max(ma,max(pmi[i],smi[i+1]));
			//cout<<pmi[i]<<' '<<smi[i+1]<<endl;
		}
		cout<<ma<<endl;
	}
}