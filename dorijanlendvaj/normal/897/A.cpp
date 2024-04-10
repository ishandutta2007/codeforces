#include <bits/stdc++.h>

using namespace std;

int n,m;
string h;
int a,b;
char c,d;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>m>>h;
	for (int i=0;i<m;++i)
	{
		cin>>a>>b>>c>>d;
		for (int j=a-1;j<b;++j)
		{
			if (h[j]==c) h[j]=d;
		}
	}
	cout<<h<<endl;
}