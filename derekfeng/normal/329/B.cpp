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
int dir[4][2]= {{0,1},{0,-1},{1,0},{-1,0}};
char c[1003][1003];
int dist[1003][1003];
int main() {
	int n,m,yx,yy,ex,ey;
	cin>>n>>m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) {
			cin>>c[i][j];
			if (c[i][j]=='E')
				ex=i,ey=j;
			if (c[i][j]=='S')
				yx=i,yy=j;
		}
	memset (dist,-1,sizeof(dist));
	queue <int> qu,qv;
	qu.push(ex),qv.push(ey);
	dist[ex][ey]=0;
	while (!qu.empty()) {
		int ux=qu.front(),vy=qv.front();
		qu.pop(),qv.pop();
		for (int i=0; i<4; i++) {
			int uu=ux+dir[i][0],vv=vy+dir[i][1];
			if (dist[uu][vv]>=0 || c[uu][vv]=='T' || uu<0 || vv<0 || uu>=n || vv>=m) continue;
			dist[uu][vv]=dist[ux][vy]+1;
			qu.push(uu);
			qv.push(vv);  
		}
	}
	int num=dist[yx][yy],ans=0;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) {
			if (c[i][j]>='1' && c[i][j]<='9');
			else continue;
			if (dist[i][j]<=num && dist[i][j]>-1) ans+=c[i][j]-'0';
		}
	cout<<ans;
	return 0;
}