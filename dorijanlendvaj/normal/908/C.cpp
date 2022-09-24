#include <bits/stdc++.h>

using namespace std;

int n,r;
pair<int,double> h[1001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>r;
	cout<<fixed<<setprecision(10);
	for (int i=0;i<n;++i)
	{
		cin>>h[i].first;
		if (i==0) h[i].second=double(r);
		else
		{
			double mah=r;
			for (int j=0;j<i;++j)
			{
				if (abs(h[i].first-h[j].first)>r*2) continue;
				mah=max(mah,h[j].second+sqrt(r*r*4.-pow(abs(h[i].first-h[j].first),2.)));
			}
			h[i].second=mah;
		}
		cout<<h[i].second<<' ';
	}
	cout<<endl;
}