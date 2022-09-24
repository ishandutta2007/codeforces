#include <bits/stdc++.h>

using namespace std;

int m1,m2;
int n,m;
int a[101],b[101];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>m;
	m1=9;
	m2=9;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		m1=min(m1,a[i]);
	}
	for (int i=0;i<m;++i)
	{
		cin>>b[i];
		m2=min(m2,b[i]);
	}
	if (m1==m2) cout<<m2<<endl;
	else
	{
		for (int i=0;i<n;++i) for (int j=0;j<m;++j) if (a[i]==b[j])
		{
			cout<<a[i]<<endl;
			return 0;
		}
		cout<<min(m1,m2)<<max(m2,m1)<<endl;
	}
}