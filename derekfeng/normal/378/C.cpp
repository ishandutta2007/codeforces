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
char c[503][503];
bool vis[503][503];
int n,m,k;
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}}; 
void dfs(int x,int y){ 
	if (vis[x][y]) return;
	vis[x][y]=1;
	for (int i=0;i<4;i++){
		int ux=x+dir[i][0],vy=y+dir[i][1];
		if (ux<0 || ux>=n || vy<0 || vy>=m ||c[ux][vy]=='#') continue;
		dfs(ux,vy);
	}
	if (k>0) c[x][y]='X';
	k--;
}
int main(){
	cin>>n>>m>>k;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			cin>>c[i][j];
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++){
			if (c[i][j]!='.') continue;
			dfs(i,j);
			for (int i=0;i<n;i++){
				for (int j=0;j<m;j++)
					cout<<c[i][j];
				cout<<endl;
			}
			return 0;
		}
}