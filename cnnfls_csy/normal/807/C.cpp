#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long n,x,y,p,q,l,r,mid;
int main()
{
	cin>>n;
	while (n--)
	{
		cin>>x>>y>>p>>q;
		if (!p)
		{
			if (x) cout<<-1<<endl;
			else cout<<0<<endl;
			continue;
		}
		if (p==q)
		{
			if (x!=y) cout<<-1<<endl;
			else cout<<0<<endl;
			continue;
		}
		if (x*q==p*y) {cout<<0<<endl;continue;}
		l=0;
		r=1e9;
		while (l+1<r)
		{
			mid=(l+r)/2;
			if (p*mid>=x&&(q-p)*mid>=(y-x)) r=mid;
			else l=mid;
		}
		cout<<q*r-y<<endl;
	}
	return 0;
}