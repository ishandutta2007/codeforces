#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
int n,m,startx,starty,endx,endy;
bool vis[1003][1003][4][4];
bool con[1003][1003][4];
char c[1003][1003];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
struct maz{
	int x,y;
	int ki,deep;
};
void bfs(){
	queue <maz> q;
	maz f={startx,starty,0,0};
	q.push(f);
	while (!q.empty()){
		maz cnt=q.front();
		q.pop();
		if (cnt.x==endx && cnt.y==endy){
			cout<<cnt.deep;
			exit(0);
		}
		for (int i=0;i<4;i++){
			if (!vis[cnt.x][cnt.y][cnt.ki][i]) continue;
			int ux=cnt.x+dir[i][0],vy=cnt.y+dir[i][1];
			if (ux<0 || vy<0 || ux>=n || vy>=m || con[ux][vy][cnt.ki] || !vis[ux][vy][cnt.ki][(i+2)%4]) continue;
			maz num;
			num={ux,vy,cnt.ki,cnt.deep+1};
			q.push(num);
			con[ux][vy][cnt.ki]=1; 
		}
		if (!con[cnt.x][cnt.y][(cnt.ki+1)%4]){
			maz num;
			num={cnt.x,cnt.y,(cnt.ki+1)%4,cnt.deep+1};
			q.push(num);
			con[cnt.x][cnt.y][(cnt.ki+1)%4]=1; 
		}
	}
}
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++){
			cin>>c[i][j];
			if (c[i][j]=='+'){
				vis[i][j][0][0]=1;
				vis[i][j][0][1]=1;
				vis[i][j][0][2]=1;
				vis[i][j][0][3]=1;
			}
			if (c[i][j]=='-'){
				vis[i][j][0][1]=1;
				vis[i][j][0][3]=1;
			}
			if (c[i][j]=='|'){
				vis[i][j][0][0]=1;
				vis[i][j][0][2]=2;
			}
			if (c[i][j]=='<'){
				vis[i][j][0][3]=1;
			}
			if (c[i][j]=='>'){
				vis[i][j][0][1]=1;
			}
			if (c[i][j]=='^'){
				vis[i][j][0][0]=1;
			}
			if (c[i][j]=='v'){
				vis[i][j][0][2]=1;
			}
			if (c[i][j]=='L'){
				vis[i][j][0][0]=1;
				vis[i][j][0][1]=1;
				vis[i][j][0][2]=1;
			}
			if (c[i][j]=='R'){
				vis[i][j][0][0]=1;
				vis[i][j][0][2]=1;
				vis[i][j][0][3]=1;
			}
			if (c[i][j]=='U'){
				vis[i][j][0][1]=1;
				vis[i][j][0][2]=1;
				vis[i][j][0][3]=1;
			}
			if (c[i][j]=='D'){
				vis[i][j][0][0]=1;
				vis[i][j][0][1]=1;
				vis[i][j][0][3]=1;
			}
			for (int l=1;l<4;l++)
				for (int p=0;p<4;p++){
					vis[i][j][l][(p+1)%4]=vis[i][j][l-1][p];
				}
		} 
	cin>>startx>>starty>>endx>>endy;
	startx--,starty--,endx--,endy--;
	bfs();
	cout<<"-1";
	return 0;
}