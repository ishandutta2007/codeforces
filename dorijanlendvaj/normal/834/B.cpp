#include <bits/stdc++.h>

using namespace std;

bool gu[101];
int zad[101];
int n,k;
int g;
string h;

int main()
{
	for (int i=0;i<26;++i) zad[i]=-1;
	cin>>n>>k>>h;
	for (int i=n-1;i>=0;--i)
	{
		if (zad[h[i]-'A']==-1) zad[h[i]-'A']=i;
	}
	for (int i=0;i<n;++i)
	{
		if (!gu[h[i]-'A'])
		{
			++g;
			gu[h[i]-'A']=true;
		}
		if (g>k)
		{
			cout<<"YES"<<endl;
			return 0;
		}
		for (int j=0;j<26;++j) if (zad[j]==i)
		{
			--g;
			gu[j]=false;
		}
	}
	cout<<"NO"<<endl;
}