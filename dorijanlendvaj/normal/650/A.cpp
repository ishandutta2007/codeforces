#include <bits/stdc++.h>

using namespace std;

map<pair<int,int>,int> s;
map<int,int> x1;
map<int,int> y1;
int x[200001],y[200001],n;
long long rez;

int main()
{
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>x[i]>>y[i];
		++x1[x[i]];
		++y1[y[i]];
		++s[make_pair(x[i],y[i])];
	}
	for (int i=0;i<n;++i)
	{
		rez+=x1[x[i]]-1+y1[y[i]]-1-s[make_pair(x[i],y[i])]+1;
	}
	cout<<rez/2<<endl;
}