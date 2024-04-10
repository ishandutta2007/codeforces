#include <bits/stdc++.h>

using namespace std;

int h[200010];
int p[200010];
bool b[200010];
int pm,m;
int n;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		p[h[i]]=n-i;
		b[h[i]]=1;
	}
	for (int i=0;i<=200000;++i)
	{
		if (b[i] && p[i]>m)
		{
			m=p[i];
			pm=i;
		}
	}
	cout<<pm<<endl;
}