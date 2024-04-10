#include <bits/stdc++.h>

using namespace std;

string a,b;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>a>>b;
	int i=1;
	cout<<a[0];
	while (i<a.size() && a[i]<b[0])
	{
		cout<<a[i];
		++i;
	}
	cout<<b[0]<<endl;
}