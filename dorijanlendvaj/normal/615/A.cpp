#include <bits/stdc++.h>

using namespace std;

bool on[101];
int n,m;
int bul;
int x;
bool e;

int main()
{
	cin>>n>>m;
	for (int i=0;i<n;++i)
	{
		cin>>x;
		for (int j=0;j<x;++j)
		{
			cin>>bul;
			on[bul-1]=true;
		}
	}
	for (int i=0;i<m;++i)
	{
		if (!on[i]) e=true;
	}
	if (e) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}