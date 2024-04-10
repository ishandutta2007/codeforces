#include <bits/stdc++.h>

using namespace std;

pair<int,int> p[100001];
map<pair<int,int>,int> m;
string h;
int n;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>h;
	if (h[0]=='0') ++p[0].first;
	else ++p[0].second;
	for (int i=1;i<n;++i)
	{
		p[i]=p[i-1];
		if (h[i]=='0') ++p[i].first;
		else ++p[i].second;
		if (p[i].first && p[i].second)
		{
			--p[i].first;
			--p[i].second;
		}
		m[p[i]]=i+1;
	}
	int rj=0;
	for (int i=0;i<n;++i)
	{
		rj=max(rj,m[p[i]]-i-1);
	}
	rj=max(rj,m[make_pair(0,0)]);
	cout<<rj<<endl;
}