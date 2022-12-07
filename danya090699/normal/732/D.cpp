#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
main()
{
	ifstream in("input.txt");
	int n, m;
	cin>>n>>m;
	int da[n], ti[m];
	for(int a=0; a<n; a++) cin>>da[a];
	for(int a=0; a<m; a++) cin>>ti[a];
	int l=-1, r=n;
	while(r-l>1)
	{
		int mid=(l+r)/2, pos=1;
		int us[m];
		vector <int> sd;
		for(int a=0; a<m; a++) us[a]=0;
		for(int a=mid; a>=0; a--)
		{
			if(da[a]!=0)
			{
				if(us[da[a]-1]==0)
				{
					sd.push_back(a);
					us[da[a]-1]=1;
				}
			}
		}
		reverse(sd.begin(), sd.end());
		if(sd.size()==m)
		{
			int tipr=0;
			for(int a=0; a<m; a++)
			{
				tipr+=ti[da[sd[a]]-1];
				if(sd[a]<a+tipr)
				{
					pos=0;
					break;
				}
			}
		}
		else pos=0;
		if(pos) r=mid;
		else l=mid;
	}
	if(r==n) cout<<-1;
	else cout<<r+1;
}