#include <bits/stdc++.h>

using namespace std;

int n;
int a[200001];
pair<int,int> b[200001];
int c[200001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for (int i=0;i<n;++i)
	{
		cin>>b[i].first;
		b[i].second=i;
	}
	sort(b,b+n);
	sort(a,a+n);
	reverse(a,a+n);
	for (int i=0;i<n;++i)
	{
		c[b[i].second]=a[i];
	}
	for (int i=0;i<n;++i) cout<<c[i]<<' ';
	cout<<endl;	
}