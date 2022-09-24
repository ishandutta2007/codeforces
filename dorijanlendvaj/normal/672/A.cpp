#include <bits/stdc++.h>

using namespace std;

string its(int a)
{
	string h1;
	while (a>0)
	{
		h1.push_back(a%10+'0');
		a/=10;
	}
	reverse(h1.begin(),h1.end());
	return h1;
}

int main()
{
	int n;
	cin>>n;
	string h;
	for (int i=1;i<=n;++i)
	{
		string nu=its(i);
		for (int j=0;j<nu.size();++j)
		{
			h.push_back(nu[j]);
		}
	}
	cout<<h[n-1]<<endl;
}