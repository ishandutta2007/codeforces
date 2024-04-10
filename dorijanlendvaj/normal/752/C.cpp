#include <bits/stdc++.h>

using namespace std;

int br,n;
string comm;
char a,b;

int main()
{
	a=' ';
	b=' ';
	cin>>n>>comm;
	br=1;
	for (int i=0;i<comm.size();++i)
	{
		if (comm[i]=='R' || comm[i]=='L')
		{
			if (a==' ') a=comm[i];
			else if (a!=comm[i])
			{
				//cout<<i<<' '<<a<<' '<<b<<endl;
				a=comm[i];
				b=' ';
				++br;
			}
		}
		else
		{
			if (b==' ') b=comm[i];
			else if (b!=comm[i])
			{
				//cout<<i<<' '<<a<<' '<<b<<endl;
				a=' ';
				b=comm[i];
				++br;
			}
		}
	}
	cout<<br<<endl;
}