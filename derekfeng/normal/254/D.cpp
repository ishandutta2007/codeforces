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
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
int n,m,d,num=0,dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int rat_x[304],rat_y[304];
char c[1003][1003];
int reachx[304][151],reachy[304][151],dist[1003][1003],now[1003][1003],reachcnt[304],dp[1003][1003],tod[1003][1003];
void no_left_output(int x,int y){
	for (int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		if (i==x && j==y)continue;
		if (c[i][j]=='X')continue;
		cout<<x<<" "<<y<<" "<<i<<" "<<j;exit(0);
	}
}
void bfs(int x,int y,int rat_xy){
	int cnt=0;
	queue<int>qu,qv;
	now[x][y]=rat_xy;
	dist[x][y]=0;
	qu.push(x),qv.push(y); 
	cnt++;
	reachx[rat_xy][cnt]=x,reachy[rat_xy][cnt]=y;
	while(qu.size()){
		int u=qu.front(),v=qv.front();
		qu.pop(),qv.pop();
		if (dist[u][v]==d) continue;
		for (int i=0;i<4;i++){
			int ux=u+dir[i][0],vy=v+dir[i][1];
			if (ux<1 || vy<1 || ux>n || vy>m || c[ux][vy]=='X' || now[ux][vy]==rat_xy) continue;
			cnt++;
			reachx[rat_xy][cnt]=ux,reachy[rat_xy][cnt]=vy;
			now[ux][vy]=rat_xy;
			dist[ux][vy]=dist[u][v]+1;
			qu.push(ux),qv.push(vy);  
		}
	}
	reachcnt[rat_xy]=cnt;
}
int main(){
	freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
	cin>>n>>m>>d;
	for (int i=1;i<=n;i++){
		scanf ("%s",c[i]+1);
		for (int j=1;j<=m;j++) if(c[i][j]=='R'){
			++num;rat_x[num]=i,rat_y[num]=j;
			if (num>=300){
				printf("-1");return 0;
			}
		}
	}
	for (int i=1;i<=num;i++)
		bfs(rat_x[i],rat_y[i],i);
	for (int i=1;i<=reachcnt[1];i++){
		vector <int> st; 
		for (int j=2;j<=num;j++){
			bool yes=0;
			for(int k=1;k<=reachcnt[j];k++)if (reachx[j][k]==reachx[1][i] && reachy[j][k]==reachy[1][i]){
				yes=1;break;
			}
			if (!yes) st.push_back(j); 
		}
		if (st.size()==0) no_left_output(reachx[1][i],reachy[1][i]);
		for (int j=0;j<st.size();j++){
			for (int k=1;k<=reachcnt[st[j]];k++){
				int u=reachx[st[j]][k],v=reachy[st[j]][k];
				if (tod[u][v]!=i) dp[u][v]=0;
				tod[u][v]=i;
				dp[u][v]++;
				if (dp[u][v]==st.size()){
					cout<<reachx[1][i]<<" "<<reachy[1][i]<<" "<<u<<" "<<v;return 0;
				}
			}
		}
	}
	cout<<"-1";
}