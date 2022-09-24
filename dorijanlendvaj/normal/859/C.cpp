#include <bits/stdc++.h>

using namespace std;

int n;
int h[101];
pair<int,int> a[51],b[51];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i) cin>>h[i];
	a[n-1]=make_pair(h[n-1],0);
	b[n-1]=make_pair(0,h[n-1]);
	for (int i=n-2;i>=0;--i)
	{
		if (b[i+1].first+h[i]>a[i+1].first)
		{
			a[i].first=b[i+1].first+h[i];
			a[i].second=b[i+1].second;
		}
		else
		{
			a[i].first=a[i+1].first;
			a[i].second=a[i+1].second+h[i];
		}
		if (a[i+1].second+h[i]>b[i+1].second)
		{
			b[i].second=a[i+1].second+h[i];
			b[i].first=a[i+1].first;
		}
		else
		{
			b[i].second=b[i+1].second;
			b[i].first=b[i+1].first+h[i];
		}
	}
	//for (int i=0;i<n;++i) cout<<a[i].first<<' '<<a[i].second<<' '<<b[i].first<<' '<<b[i].second<<endl;
	cout<<a[0].second<<' '<<a[0].first<<endl;
}