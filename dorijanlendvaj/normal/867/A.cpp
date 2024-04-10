#include <bits/stdc++.h>

using namespace std;

int f,s,n;
string h;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	cin>>h;
	for (int i=1;i<h.size();++i)
	{
		if (h[i-1]=='S' && h[i]=='F') ++f;
		else if (h[i-1]=='F' && h[i]=='S') ++s;
	}
	if (f>s) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}