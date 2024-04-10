#include <bits/stdc++.h>

using namespace std;

int n;
int h[101][101];
string rj;

int main()
{
	cin>>n;
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<n;++j) cin>>h[i][j];
	}
	rj="Yes";
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<n;++j)
		{
			if (h[i][j]==1) continue;
			bool a=false;
			for (int i1=0;i1<n;++i1)
			{
				if (i1==i) continue;
				for (int j1=0;j1<n;++j1)
				{
					if (j1==j) continue;
					if (h[i][j1]+h[i1][j]==h[i][j]) a=true;
				}
			}
			if (!a) rj="No";
		}
	}
	cout<<rj<<endl;
}