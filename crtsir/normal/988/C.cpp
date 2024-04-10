#include<bits/stdc++.h>
using namespace std;
int a[201862],n,x;
map<int,pair<int,int> >mp;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		cin>>x;
		for(int j=0;j<x;j++)
			cin>>a[j],
			cnt+=a[j];
		for(int j=0;j<x;j++)
		{
			int res=cnt-a[j];
			if(mp[res].first!=0&&mp[res].first!=i)
			{
				cout<<"YES"<<endl;
				cout<<mp[res].first<<' '<<mp[res].second<<endl;
				cout<<i<<' '<<j+1;
				return 0;
			}
			mp[res]=make_pair(i,j+1);
		}
	}
	cout<<"NO";
}
/*                    |
                     /o\
                     |o|
                     |o|
                     |o|
                     |o|
                    /   \
                    |TNT|
                    |___|
*/