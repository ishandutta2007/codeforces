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
int n,m;
set <int> q;
vector <int> g[100004];
bool vis[100004];
void dfs(int x){
	cout<<x<<" ";
	vis[x]=1;
	for (int i=0;i<g[x].size();i++)
		if (!vis[g[x][i]])
			q.insert(g[x][i]);
	if (int(q.size())==0) return;
	int ld=*q.begin();
	q.erase(q.begin());
	dfs(ld); 
}
int main(){
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x); 
	}
	dfs(1);
}