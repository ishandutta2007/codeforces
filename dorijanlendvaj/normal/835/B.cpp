#include <bits/stdc++.h>

using namespace std;

int k,nk;
string n;

int main()
{
	cin>>k>>n;
	for (int i=0;i<n.size();++i)
	{
		nk+=n[i]-'0';
	}
	sort(n.begin(),n.end());
	int br=0;
	while (nk<k)
	{
		nk+='9'-n[br];
		++br;
	}
	cout<<br<<endl;
}