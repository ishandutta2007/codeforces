#include <bits/stdc++.h>

using namespace std;

int h[1501];
int n,inv;
int q;
int a,b;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
	}
	for (int i=0;i<n;++i)
	{
		for (int j=i+1;j<n;++j)
		{
			if (h[i]>h[j]) ++inv;
		}
	}
	cin>>q;
	inv%=2;
	for (int i=0;i<q;++i)
	{
		cin>>a>>b;
		a=abs(a-b);
		a=a*(a+1)/2;
		inv+=a;
		inv%=2;
		if (inv==1) cout<<"odd"<<endl;
		else cout<<"even"<<endl;
	}
}