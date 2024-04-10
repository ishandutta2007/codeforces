#include <bits/stdc++.h>

using namespace std;

int n;
string a;
string h;
bool c,d;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>a>>n;
	for (int i=0;i<n;++i)
	{
		cin>>h;
		if (h[0]==a[1]) c=1;
		if (h[1]==a[0]) d=1;
		if (h[0]==a[0] && h[1]==a[1])
		{
			c=1;
			d=1;
		}
	}
	if (c && d) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}