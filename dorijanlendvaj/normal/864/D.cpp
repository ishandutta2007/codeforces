#include <bits/stdc++.h>

using namespace std;

int n,cur;
int h[200001],app[200001],las[200001];
vector<int> mis;
bool tak[200001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		++app[h[i]];
	}
	for (int i=n-1;i>=0;--i)
	{
		if (las[h[i]]==0) las[h[i]]=i;
	}
	for (int i=1;i<=n;++i) if (!app[i]) mis.push_back(i);
	cout<<mis.size()<<endl;
	for (int i=0;i<n;++i) if (app[h[i]]>1)
	{
		if ((!tak[h[i]] && h[i]<mis[cur]) || (las[h[i]]==i && !tak[h[i]]))
		{
			tak[h[i]]=1;
		}
		else
		{
			h[i]=mis[cur];
			++cur;
		}
	}
	for (int i=0;i<n;++i) cout<<h[i]<<' ';
	cout<<endl;
}