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
typedef pair<int,int> pii;
int n,m;
struct maz{
	char p;
	int x,y;
};
char c[503][503];
bool vis[503][503];
vector <pii> str;
vector <maz> ans; 
int dir[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};
void dfs(int x,int y){
	if (x<0 || y<0 || x>=n || y>=m) return;
	if (vis[x][y] || c[x][y]=='#') return;
	vis[x][y]=1;
	str.push_back(pii(x,y));
	for (int i=0;i<4;i++) {
		int xx=x+dir[i][0],yy=y+dir[i][1];
		dfs(xx,yy);
	}
}
int main() {
	memset (vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++)
		scanf("%s",c[i]);
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (c[i][j]=='.'){
				ans.push_back({'B',i+1,j+1}); 
			}
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++){
			if (vis[i][j] ||  c[i][j]=='#')continue;
			str.clear();
			dfs(i,j);
			reverse(str.begin(),str.end());
			for (int k=0;k<str.size()-1;k++){
				ans.push_back({'D',str[k].first+1,str[k].second+1}); 
				ans.push_back({'R',str[k].first+1,str[k].second+1}); 
			}
		}
	printf ("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)
		printf("%c %d %d\n",ans[i].p,ans[i].x,ans[i].y); 
	return 0;
}