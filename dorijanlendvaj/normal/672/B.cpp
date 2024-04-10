#include <bits/stdc++.h>

using namespace std;

set<char> a;
string h;
int n;

int main()
{
	cin>>n>>h;
	if (n>26) cout<<-1<<endl;
	else
	{
		for (int i=0;i<n;++i)
		{
			a.insert(h[i]);
		}
		cout<<n-a.size()<<endl;
	}
}