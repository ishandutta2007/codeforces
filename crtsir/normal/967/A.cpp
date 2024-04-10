#include<bits/stdc++.h>
using namespace std;
pair<int,int>tim[103];
int main()
{
	int n,s;
	cin>>n>>s;
	for(int i=0;i<n;i++)
		cin>>tim[i].first>>tim[i].second;
	if(tim[0].first*60+tim[0].second-s>0)
	{
		cout<<"0 0";
		return 0;
	}
	for(int i=0;i<n-1;i++)
		if(60*(tim[i+1].first-tim[i].first)+tim[i+1].second-tim[i].second>s*2+1)
		{
			cout<<tim[i].first+(tim[i].second+s+1)/60<<' '<<(tim[i].second+s+1)%60;
			return 0;
		}
	cout<<tim[n-1].first+(tim[n-1].second+s+1)/60<<' '<<(tim[n-1].second+s+1)%60;
}