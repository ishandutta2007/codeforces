#include <bits/stdc++.h>

using namespace std;

int n;
string a,b;
vector<int> ab,ba;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>a>>b;
	for (int i=0;i<n;++i)
	{
		if (a[i]=='a' && b[i]=='b') ab.push_back(i);
		if (a[i]=='b' && b[i]=='a') ba.push_back(i);
	}
	if (ab.size()%2!=ba.size()%2)
	{
		cout<<-1;
		return 0;
	}
	vector<pair<int,int>> v;
	while (ab.size()>=2)
	{
		int x=ab.back();
		ab.pop_back();
		int y=ab.back();
		ab.pop_back();
		v.emplace_back(x,y);
	}
	while (ba.size()>=2)
	{
		int x=ba.back();
		ba.pop_back();
		int y=ba.back();
		ba.pop_back();
		v.emplace_back(x,y);
	}
	if (ab.size())
	{
		int x=ab.back();
		int y=ba.back();
		v.emplace_back(x,x);
		v.emplace_back(x,y);
	}
	cout<<v.size()<<endl;
	for (int i=0;i<v.size();++i) cout<<v[i].first+1<<' '<<v[i].second+1<<'\n';
}