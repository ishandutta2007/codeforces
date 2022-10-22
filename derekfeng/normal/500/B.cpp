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
int n;
bool vis[303];
int p[303];
vector <int> g[303];
vector <int> t[303];
void dfs(int x,int qq){
	if (vis[x]) return;
	t[qq].push_back(x);
	vis[x]=1;
	for (int i=0;i<g[x].size();i++)
		dfs(g[x][i],qq);
}
bool has[303];
int ans[303];
int main(){
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>p[i];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			char c;
			cin>>c;
			if (c=='1'){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	for (int i=0;i<n;i++){
		memset (vis,0,sizeof(vis));
		dfs(i,p[i]);
		sort (t[p[i]].begin(),t[p[i]].end());
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<t[i].size();j++){
			if (!has[t[i][j]]){
				ans[t[i][j]]=i;
				has[t[i][j]]=1;
				break;
			}
		}
	}
	for (int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}