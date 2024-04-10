#include <bits/stdc++.h>

using namespace std;

int n,k;
string h[100001];
map<string,int> ma;

void adma(string a,int d)
{
	if (d==k)
	{
		++ma[a];
		return;
	}
	if (a[d]=='1') adma(a,d+1);
	else
	{
		a[d]='1';
		adma(a,d+1);
		a[d]='0';
		adma(a,d+1);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<k;++j)
		{
			char a;
			cin>>a;
			h[i].push_back(a);
		}
		//cout<<h[i]<<endl;
		adma(h[i],0);
	}
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<k;++j)
		{
			if (h[i][j]=='0') h[i][j]='1';
			else h[i][j]='0';
		}
		if (ma[h[i]])
		{
			cout<<"YES"<<endl;
			return 0;
		}
		for (int j=0;j<k;++j)
		{
			if (h[i][j]=='0') h[i][j]='1';
			else h[i][j]='0';
		}
	}
	cout<<"NO"<<endl;
}