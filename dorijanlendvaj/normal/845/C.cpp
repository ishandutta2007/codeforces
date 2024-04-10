#include <bits/stdc++.h>

using namespace std;

int n,c;
int a[200001],b[200001];
map<int,int> vr;
int pr[400001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>a[i]>>b[i];
		++b[i];
		++vr[a[i]];
		--vr[b[i]];
	}
	for (map<int,int>::iterator it=vr.begin();it!=vr.end();++it)
	{
		pr[c]=it->second;
		++c;
	}
	for (int i=1;i<n*2;++i) pr[i]=pr[i]+pr[i-1];
	for (int i=0;i<n*2;++i) if (pr[i]>2)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
}