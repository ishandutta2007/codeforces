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
int x[3],y[3];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
vector <int> res1,res2;	
bool vis[1003][1003]; 
int dist[1003][1003];
void bfs(int xx,int yy,int x1,int x2){
	for (int i=0;i<1003;i++)
		for (int j=0;j<1003;j++)
			dist[i][j]=1e9;
	dist[xx][yy]=0;
	queue <int> q1,q2;
	q1.push(xx),q2.push(yy);
	while (!q1.empty()){
		int u=q1.front(),v=q2.front();
		q1.pop(),q2.pop();
		if (u==x1 && v==x2) break;
		for (int i=0;i<4;i++){
			int u1=dir[i][0]+u,v1=dir[i][1]+v;
			if (u1<0 || v1<0 || u1>1000 || v1>1000) continue;
			if (dist[u1][v1]>dist[u][v]+1){
				dist[u1][v1]=dist[u][v]+1;
				q1.push(u1),q2.push(v1);   
			}
		}
	}
	int i=x1,j=x2;
	for (;;){
		if (!vis[i][j])res1.push_back(i),res2.push_back(j);
		vis[i][j]=1;
		if (i==xx && j==yy) break;
		for (int q=0;q<4;q++){
			if (i+dir[q][0]<0 || i+dir[q][0]>1002 || j+dir[q][1]<0 || j+dir[q][1]>1002) continue;
			if (dist[i+dir[q][0]][j+dir[q][1]]==dist[i][j]-1){
				i=i+dir[q][0],j=j+dir[q][1];
				break;
			}
		}
	}
}
int main(){
	for (int i=0;i<3;i++) cin>>x[i]>>y[i];
	int num=0;
	int a,b,c,ans;
	if (abs(x[0]-x[1])+abs(y[0]-y[1])>num){
		a=0,b=1;
		num=abs(x[0]-x[1])+abs(y[0]-y[1]);
	}
	if (abs(x[0]-x[2])+abs(y[0]-y[2])>num){
		a=0,b=2;
		num=abs(x[0]-x[2])+abs(y[0]-y[2]);
	}
	if (abs(x[1]-x[2])+abs(y[1]-y[2])>num){
		a=1,b=2;
		num=abs(x[1]-x[2])+abs(y[1]-y[2]);
	}
	c=3-a-b,ans=abs(x[a]-x[b])+abs(y[a]-y[b])+1;
	int ax,bx,ay,by;
	ax=x[a],bx=x[b];
	ay=y[a],by=y[b];
	if (ax>bx) swap(ax,bx);
	if (ay>by) swap(ay,by); 
	if (y[c]<ay){
		ans+=ay-y[c]; 
	}
	else if (y[c]>by){
		ans+=y[c]-by;
	}
	if (x[c]<ax){
		ans+=x[c]-ax; 
	}
	else if (x[c]>bx){
		ans+=x[c]-bx; 
	}
	num=1e9;
	int a1=-1,b1=-1;
	for (int i=ax;i<=bx;i++)
		for (int j=ay;j<=by;j++){
			if (abs(x[c]-i)+abs(y[c]-j)<num){
				a1=i,b1=j;
				num=abs(x[c]-i)+abs(y[c]-j);
			}
	}
	bfs(a1,b1,x[0],y[0]);
	bfs(a1,b1,x[1],y[1]);
	bfs(a1,b1,x[2],y[2]); 
	cout<<res1.size()<<endl;
	for (int i=0;i<res1.size();i++)
		cout<<res1[i]<<" "<<res2[i]<<endl;
}