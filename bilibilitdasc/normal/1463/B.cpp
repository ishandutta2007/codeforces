#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector <long long> a;
		long long al,smod=0,smev=0;//sum of odd and dum of even
		cin>>al;
		for(long long i=0;i<al;i++)
		{
			long long lsbl;//
			cin>>lsbl;
			a.push_back(lsbl);
			if(i%2)
			smod+=lsbl;
			else
			smev+=lsbl; 
		}
		if(smod>smev)
		{
			for(long long i=0;i<al;i++)
			if(i%2==0)
			a[i]=1;
		}
		else
		{
			for(long long i=0;i<al;i++)
			if(i%2)
			a[i]=1;
		}
		for(long long i=0;i<al;i++)
		cout<<a[i]<<' ';
		cout<<'\n';
	}
	return 0;
}