#include <bits/stdc++.h>

using namespace std;

int xaxafg;
string h;
string rj;
int znam;

int main()
{
	std::cin.sync_with_stdio(false);
	cin>>xaxafg>>h;
	for (int i=0;i<h.size();++i)
	{
		if (h[i]=='1') ++znam;
		else
		{
			rj.push_back(znam+'0');
			znam=0;
		}
	}
	rj.push_back(znam+'0');
	znam=0;
	cout<<rj<<endl;
}