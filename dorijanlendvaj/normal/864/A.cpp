#include <bits/stdc++.h>

using namespace std;

int brn,n,h,a,b,sa,sb;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>h;
		if (h!=sa && h!=sb)
		{
			if (sa) sb=h;
			else sa=h;
			++brn;
			if (brn==3)
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		if (h==sa) ++a;
		if (h==sb) ++b;
	}
	if (a==b && a==n/2) cout<<"YES"<<endl<<sa<<' '<<sb<<endl;
	else cout<<"NO"<<endl;
}