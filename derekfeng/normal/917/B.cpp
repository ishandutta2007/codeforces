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
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
int n,m;
vector <pii> g[103];
int win[103][103][26];
int dfs(int x,int y,int q){
	if (win[x][y][q]!=-1)
		return win[x][y][q];
	win[x][y][q]=0;
	for (int i=0;i<g[x].size();i++){
		if (g[x][i].se<q) continue;
		if (dfs(y,g[x][i].fi,g[x][i].se)==0){
			win[x][y][q]=1;
			return 1;
		}
	}
	return 0;
}
int main(){
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int x,y;
		char c;
		cin>>x>>y>>c;
		g[x].push_back(mkp(y,c-'a')); 
	}
	memset (win,-1,sizeof(win));
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			cout<<char('B'-dfs(i,j,0));
		cout<<endl;
	}
}