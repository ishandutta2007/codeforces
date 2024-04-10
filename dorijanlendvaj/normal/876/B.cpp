#include <bits/stdc++.h>

using namespace std;

int h[100001];
vector<int> c[100001];
int ma,n,m,k;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>k>>m;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		c[h[i]%m].push_back(h[i]);
	}
	for (int i=0;i<m;++i)
	{
		if (c[i].size()<k) continue;
		cout<<"Yes"<<endl;
		for (int j=0;j<k;++j)
		{
			cout<<c[i][j]<<' ';
		}
		cout<<endl;
		return 0;
	}
	cout<<"No"<<endl;
}