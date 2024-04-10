#include<bits/stdc++.h>
using namespace std;
char c;
bool l[1003][1003][4];
int need[4][4]={
{0,3,2,1},
{1,0,3,2},
{2,1,0,3},
{3,2,1,0}
};
int n,m,dy[4]={0,1,0,-1},dx[4]={-1,0,1,0},ans[1003][1003][4];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>c;
			if(c=='^')l[i][j][0]=1;
			if(c=='>')l[i][j][1]=1;
			if(c=='v')l[i][j][2]=1;
			if(c=='<')l[i][j][3]=1;
			if(c=='+'){l[i][j][0]=1;l[i][j][1]=1;l[i][j][2]=1;l[i][j][3]=1;}
			if(c=='-'){l[i][j][1]=1;l[i][j][3]=1;}
			if(c=='|'){l[i][j][0]=1;l[i][j][2]=1;}
			if(c=='U'){l[i][j][1]=1;l[i][j][2]=1;l[i][j][3]=1;}
			if(c=='R'){l[i][j][0]=1;l[i][j][2]=1;l[i][j][3]=1;}
			if(c=='D'){l[i][j][0]=1;l[i][j][1]=1;l[i][j][3]=1;}
			if(c=='L'){l[i][j][0]=1;l[i][j][1]=1;l[i][j][2]=1;}
			ans[i][j][0]=2147483647;
			ans[i][j][1]=2147483647;
			ans[i][j][2]=2147483647;
			ans[i][j][3]=2147483647;
		}
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	queue<pair<pair<int,int>,pair<int,int> > >q;
	q.push(make_pair(make_pair(x1-1,y1-1),make_pair(0,0)));
	ans[x1-1][y1-1][0]=0;
	while(!q.empty()){
		//cout<<q.front().first.first+1<<' '<<q.front().first.second+1<<' '<<q.front().second.first<<endl;
		if(q.front().first.first==x2-1&&q.front().first.second==y2-1)
		{
			cout<<ans[x2-1][y2-1][q.front().second.first];
			return 0;
		}
		if(ans[q.front().first.first][q.front().first.second][(q.front().second.first+1)%4]>
		1+ans[q.front().first.first][q.front().first.second][q.front().second.first])
			q.push(make_pair(q.front().first,make_pair((q.front().second.first+1)%4,q.front().second.second+1))),
			ans[q.front().first.first][q.front().first.second][(q.front().second.first+1)%4]=
			1+ans[q.front().first.first][q.front().first.second][q.front().second.first];
		for(int j=0;j<4;j++)
		{
			int x=q.front().first.first,y=q.front().first.second;
			int xx=x+dx[j],yy=y+dy[j];
			if(xx>-1&&yy>-1&&xx<n&&yy<m)
				if(l[x][y][(j+16-q.front().second.first)%4]&&l[xx][yy][(j+18-q.front().second.first)%4])
					if(2147483647==ans[xx][yy][q.front().second.first%4])
						ans[xx][yy][q.front().second.first%4]=1+ans[x][y][q.front().second.first%4],
						q.push(make_pair(make_pair(xx,yy),make_pair(q.front().second.first%4,0)));
		}
		q.pop();
	}
	cout<<-1;
}
/*
0:
0 1 2 3
0 3 2 1
1:
0 1 2 3
1 0 3 2
2:
0 1 2 3
2 1 0 3
3:
0 1 2 3
3 2 1 0*/