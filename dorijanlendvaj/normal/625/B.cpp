#include <bits/stdc++.h>

using namespace std;

string a,b;
int rez;

int main()
{
	cin>>a>>b;
	for (int i=0;i<=a.size()-b.size();++i)
	{
		if (i==a.size()) break;
		if (a.substr(i,b.size())==b)
		{
			++rez;
			i+=b.size()-1;
		}
	}
	cout<<rez<<endl;
}