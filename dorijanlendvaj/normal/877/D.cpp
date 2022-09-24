#include <bits/stdc++.h>

using namespace std;

int n,m;
string h[1001];
int dist[1001][1001];
bool bio[1001][1001];
queue<pair<int,int> > q;
int x1,y1,x2,y2,k;

void bfs()
{
	q.push(make_pair(x1,y1));
	dist[x1][y1]=0;
	while (q.size())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		bio[x][y]=1;
		int br=0;
		for (int i=x-1;br<k && i>=0 && h[i][y]=='.' && dist[i][y]>=dist[x][y]+1;--i)
		{
			if (!bio[i][y])
			{
				dist[i][y]=dist[x][y]+1;
				q.push(make_pair(i,y));
				bio[i][y]=1;
			}
			++br;
		}
		br=0;
		for (int i=x+1;br<k && i<n && h[i][y]=='.' && dist[i][y]>=dist[x][y]+1;++i)
		{
			if (!bio[i][y])
			{
				dist[i][y]=dist[x][y]+1;
				q.push(make_pair(i,y));
				bio[i][y]=1;
			}
			++br;
		}
		br=0;
		for (int i=y+1;br<k && i<m && h[x][i]=='.' && dist[x][i]>=dist[x][y]+1;++i)
		{
			if (!bio[x][i])
			{
				dist[x][i]=dist[x][y]+1;
				q.push(make_pair(x,i));
				bio[x][i]=1;
			}
			++br;
		}
		br=0;
		for (int i=y-1;br<k && i>=0 && h[x][i]=='.' && dist[x][i]>=dist[x][y]+1;--i)
		{
			if (!bio[x][i])
			{
				dist[x][i]=dist[x][y]+1;
				q.push(make_pair(x,i));
				bio[x][i]=1;
			}
			++br;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	for (int i=0;i<n;++i) cin>>h[i];
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) dist[i][j]=1000001;
	cin>>x1>>y1>>x2>>y2;
	--x1;
	--x2;
	--y1;
	--y2;
	bfs();
	if (dist[x2][y2]==1000001) cout<<-1<<endl;
	else cout<<dist[x2][y2]<<endl;
}