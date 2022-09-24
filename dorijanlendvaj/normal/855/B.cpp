#include <bits/stdc++.h>

using namespace std;

long long n,p,q,r,rj;
long long h[100001];
long long pr1[100001],pr2[100001],pr3[100001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>p>>q>>r;
	rj=-5000000000000000000;
	//cout<<rj<<endl;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		if (i==0)
		{
			pr1[i]=h[i]*p;
			pr2[i]=h[i]*(p+q);
			pr3[i]=h[i]*(p+r+q);
		}
		else
		{
			pr1[i]=max(pr1[i-1],h[i]*p);
			pr2[i]=max(pr2[i-1],pr1[i]+h[i]*q);
			pr3[i]=max(pr3[i-1],pr2[i]+h[i]*r);
		}
		//cout<<pr1[i]<<' '<<pr2[i]<<' '<<pr3[i]<<endl;
	}
	cout<<pr3[n-1]<<endl;
}