#include <bits/stdc++.h>

using namespace std;

long long n,l;
long long c[31];
pair<double,long long> pl[31];
long long rj=1ll<<61;

long long l2(long long a)
{
	long long rj=0;
	while (a)
	{
		a/=2;
		++rj;
	}
	return rj;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>l;
	for (int i=0;i<n;++i)
	{
		cin>>c[i];
		pl[i]={c[i]*1./(1<<i),i};
	}
	sort(pl,pl+n);
	for (int j=0;j<31;++j)
	{
		long long l1=l;
		if (!(l&(1<<j)))
		{
			l=(l>>j);
			l|=1;
			l=(l<<j);
		}
		long long r=0;
		for (int i=0;i<n && l;++i)
		{
			//cout<<r<<' '<<l<<' '<<pl[i].first<<' '<<pl[i].second<<endl;
			r+=c[pl[i].second]*(l/(1<<pl[i].second));
			l%=(1<<pl[i].second);
			//cout<<r<<' '<<l<<' '<<pl[i].first<<' '<<pl[i].second<<endl;
		}
		rj=min(rj,r);
		l=l1;
	}
	cout<<rj<<endl;
}