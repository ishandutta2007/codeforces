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
int n,m;
char c[1003][1003];
int dist[1003][1003][4];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
void bfs(char ct,int x){
	queue <int> qu,qv;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (c[i][j]==ct){
				qu.push(i),qv.push(j);
				dist[i][j][x]=0;
			}
	while (!qu.empty()){
		int u=qu.front(),v=qv.front();
		qu.pop(),qv.pop();
		for (int i=0;i<4;i++){
			int ux=u+dir[i][0],vy=v+dir[i][1];
			if (ux<0 || vy<0 || ux>=n || vy>=m || c[ux][vy]=='#') continue;
			if (dist[ux][vy][x]>dist[u][v][x]+(c[ux][vy]=='.')){
				dist[ux][vy][x]=dist[u][v][x]+(c[ux][vy]=='.');
				qu.push(ux),qv.push(vy);  
			}
		}
	}
}
int main(){
	for (int i=0;i<1003;i++)
		for (int j=0;j<1003;j++)
			for (int l=0;l<4;l++)
				dist[i][j][l]=1e8; 
	cin>>n>>m; 
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			cin>>c[i][j];
	bfs('1',1);
	bfs('2',2);
	bfs('3',3);
	int ans=1e9;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++){
			int res=dist[i][j][1]+dist[i][j][2]+dist[i][j][3];
			if (c[i][j]=='.') res-=2;
			ans=min(res,ans);
		}
	if (ans>=1e8) cout<<"-1";
	else cout<<ans;
	return 0;
}