#include <iostream>
#include <fstream>
#include <set>
#define int long long
using namespace std;
main()
{
	ifstream in("input.txt");
	int n, k, x, nq=0, sign=1;
	cin>>n>>k>>x;
	int ar2[n], ar[n];
	for(int a=0; a<n; a++)
	{
		cin>>ar2[a];
		ar[a]=ar2[a];
		if(ar2[a]==0) nq++;
	}
	if(nq<=k)
	{
		k-=nq;
		for(int a=0; a<n; a++)
		{
			if(ar2[a]==0) ar[a]=x;
			else ar[a]=ar2[a];
			if(ar[a]<0) sign*=-1;
		}
		if((sign==1)and(nq!=0))
		{
			for(int a=0; a<n; a++)
			{
				if(ar2[a]==0)
				{
					ar[a]=-x;
					sign=-1;
					break;
				}
			}
		}
		set <pair <int, int> > sp;
		for(int a=0; a<n; a++)
		{
			if(ar[a]<0) sp.insert(make_pair(-ar[a], a));
			else sp.insert(make_pair(ar[a], a));
		}
		if(sign==1)
		{
			int sma=(*sp.begin()).first, smanu=(*sp.begin()).second;
			sp.erase(sp.begin());
			if(k<sma/x+1)
			{
				if(ar[smanu]<0) ar[smanu]+=x*k;
				else ar[smanu]-=x*k;
				k=0;
			}
			else
			{
				if(ar[smanu]<0)
				{
					ar[smanu]+=x*(sma/x+1);
					sp.insert(make_pair(ar[smanu], smanu));
				}
				else
				{
					ar[smanu]-=x*(sma/x+1);
					sp.insert(make_pair(-ar[smanu], smanu));
				}
				k-=sma/x+1;
			}
		}
		while(k!=0)
		{
			int sma=(*sp.begin()).first, smanu=(*sp.begin()).second;
			sp.erase(sp.begin());
			if(ar[smanu]<0)
			{
				ar[smanu]-=x;
				sp.insert(make_pair(-ar[smanu], smanu));
			}
			else
			{
				ar[smanu]+=x;
				sp.insert(make_pair(ar[smanu], smanu));
			}
			k--;
		}
	}
	for(int a=0; a<n; a++) cout<<ar[a]<<" ";
}