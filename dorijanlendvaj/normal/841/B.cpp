#include <bits/stdc++.h>

using namespace std;

int o,e,n;
int h[1000001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		if (h[i]%2) ++o;
		else ++e;
	}
	if (o>0) cout<<"First"<<endl;
	else cout<<"Second"<<endl;
}