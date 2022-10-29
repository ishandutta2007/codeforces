#include<bits/stdc++.h>
using namespace std;
const int len=3e5+5;
vector<pair<int,int> >v1,v2;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int a,b;
		cin>>a>>b;
		if(a<b)v1.push_back({-b,i});
		else v2.push_back({b,i});
	}
	if(v1.size()<v2.size())swap(v1,v2);
	cout<<v1.size()<<endl;
	sort(v1.begin(),v1.end());
	for(int i=0;i<v1.size();++i)cout<<v1[i].second<<' ';
}