#include <bits/stdc++.h>

using namespace std;

string h[101];
const int n=10;

bool prov()
{
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<6;++j)
		{
			if (h[i][j+0]=='X' && h[i][j+1]=='X' && h[i][j+2]=='X' && h[i][j+3]=='X' && h[i][j+4]=='X') return true;
		}
	}
	for (int i=0;i<6;++i)
	{
		for (int j=0;j<n;++j)
		{
			if (h[i][j]=='X' && h[i+1][j]=='X' && h[i+2][j]=='X' && h[i+3][j]=='X' && h[i+4][j]=='X') return true;
		}
	}
	for (int i=0;i<6;++i)
	{
		for (int j=0;j<6;++j)
		{
			if (h[i][j]=='X' && h[i+1][j+1]=='X' && h[i+2][j+2]=='X' && h[i+3][j+3]=='X' && h[i+4][j+4]=='X') return true;
		}
	}
	for (int i=0;i<6;++i)
	{
		for (int j=9;j>=4;--j)
		{
			if (h[i][j]=='X' && h[i+1][j-1]=='X' && h[i+2][j-2]=='X' && h[i+3][j-3]=='X' && h[i+4][j-4]=='X') return true;
		}
	}
	return false;
}

int main()
{
	std::cin.sync_with_stdio(false);
	for (int i=0;i<n;++i) cin>>h[i];
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<n;++j)
		{
			if (h[i][j]=='.')
			{
				h[i][j]='X';
				if (prov())
				{
					cout<<"YES"<<endl;
					return 0;
				}
				h[i][j]='.';
			}
		}
	}
	cout<<"NO"<<endl;
}