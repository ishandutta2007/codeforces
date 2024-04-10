//I hate test 9.
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
int n,m,startx,starty,ex,ey;
char c[1003][1003];
int dist[1003][1003];
struct Turn{
	int x,y;
};
int main() {
	cin>>n>>m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) {
			cin>>c[i][j];
			if (c[i][j]=='S') startx=i,starty=j;
			if (c[i][j]=='T') ex=i,ey=j;
		}
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			dist[i][j]=1e9;
	queue <Turn> q;
	dist[startx][starty]=0;
	q.push({startx,starty});
	while (!q.empty()) {
		int x=q.front().x,y=q.front().y;
		q.pop();
		for (int i=x+1; i<n; i++) {
			if (dist[i][y]>dist[x][y] && c[i][y]!='*') {
				dist[i][y]=dist[x][y]+1;
				q.push({i,y});
			} else break;
		}
		for (int i=x-1; i>=0; i--) {
			if (dist[i][y]>dist[x][y] && c[i][y]!='*') {
				dist[i][y]=dist[x][y]+1;
				q.push({i,y});
			} 
			else break;
		}
		for (int i=y+1; i<m; i++) {
			if (dist[x][i]>dist[x][y] && c[x][i]!='*') {
				dist[x][i]=dist[x][y]+1;
				q.push({x,i});
			}
			else break;
		}
		for (int i=y-1; i>=0; i--) {
			if (dist[x][i]>dist[x][y] && c[x][i]!='*') {
				dist[x][i]=dist[x][y]+1;
				q.push({x,i});
			} else break;
		}
	}
	if (dist[ex][ey]<=3)cout<<"YES";
	else cout<<"NO";
	return 0;
}