#include <bits/stdc++.h>

using namespace std;

string h[11][11][11];
int a,b,oc;

int main()
{
	std::ios_base::sync_with_stdio(false);
	for (int i=0;i<3;++i)
	{
		for (int j=0;j<3;++j)
		{
			for (int k=0;k<3;++k)
			{
				cin>>h[i][k][j];
			}
		}
	}
	cin>>a>>b;
	--a;
	--b;
	a%=3;
	b%=3;
	for (int i=0;i<3;++i)
	{
		for (int j=0;j<3;++j)
		{
			if (h[a][b][i][j]=='o' || h[a][b][i][j]=='x') ++oc;
			else h[a][b][i][j]='!';
		}
	}
	if (oc==9)
	{
		for (int i=0;i<3;++i)
		{
			for (int j=0;j<3;++j)
			{
				for (int k=0;k<3;++k)
				{
					for (int l=0;l<3;++l)
					{
						if (h[i][j][k][l]=='.') h[i][j][k][l]='!';
					}
				}
			}
		}
	}
	for (int i=0;i<3;++i)
	{
		for (int j=0;j<3;++j)
		{
			for (int k=0;k<3;++k) cout<<h[i][k][j]<<' ';
			cout<<endl;
		}
		cout<<endl;
	}
}