#include <bits/stdc++.h>

using namespace std;

int br;
int n,m;
string a[100001],b[100001];

int main()
{
	cin>>n>>m;
	for (int i=0;i<n;++i) cin>>a[i];
	for (int i=0;i<m;++i) cin>>b[i];
	if (n>m) cout<<"YES"<<endl;
	else if (m>n) cout<<"NO"<<endl;
	else
	{
		for (int i=0;i<n;++i)
		{
			for (int j=0;j<m;++j)
			{
				if (a[i]==b[j])
				{
					++br;
					//cout<<a[i]<<' '<<b[j]<<endl;
				}
			}
		}
		if (br%2) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}