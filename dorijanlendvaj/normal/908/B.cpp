#include <bits/stdc++.h>

using namespace std;

pair<int,int> ma[]={{-1,0},{0,-1},{0,1},{1,0}};
string h[101];
int n,m,x1,y1,rj;
string inst;

bool ch(int x,int y)
{
	for (int i=0;i<inst.size();++i)
	{
		x+=ma[inst[i]-'0'].first;
		y+=ma[inst[i]-'0'].second;
		if (x>=n || x<0 || y>=m || y<0 || h[x][y]=='#') return 0;
		if (h[x][y]=='E') return 1;
	}
	return 0;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=0;i<n;++i) cin>>h[i];
	cin>>inst;
	for (int i=0;i<n;++i) for (int j=0;j<m;++j)
	{
		if (h[i][j]=='S')
		{
			x1=i;
			y1=j;
		}
	}
	do
	{
		rj+=ch(x1,y1);
		//for (int i=0;i<4;++i) cout<<ma[i].first<<' '<<ma[i].second<<endl;
		//cout<<endl;
	}
	while (next_permutation(ma,ma+4));
	cout<<rj<<endl;
}