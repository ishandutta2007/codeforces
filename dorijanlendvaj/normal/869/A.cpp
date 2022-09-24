#include <bits/stdc++.h>

using namespace std;

long long n,a[10001],b[10001],rj;
bool app[5000010];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		app[a[i]]=1;
	}
	for (int i=0;i<n;++i)
	{
		cin>>b[i];
		app[b[i]]=1;
	}
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<n;++j)
		{
			if (app[a[i]^b[j]]) ++rj;
		}
	}
	if (rj%2) cout<<"Koyomi"<<endl;
	else cout<<"Karen"<<endl;
}