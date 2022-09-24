#include <bits/stdc++.h>

using namespace std;

int n;
string h[100001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		bool ima=false;
		for (int j=0;j<i;++j) ima|=(h[j]==h[i]);
		if (ima) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}