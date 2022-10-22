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
const int MOD=1e9+7;
int n;
int x[5003],y[5003];
int dist[5003][5003];
int res=0;
vector <int> g[5003];
int vis[5003];
bool dfs(int xx,int p){
	vis[xx]=p;
	for (int i=0;i<g[xx].size();i++){
		if (vis[g[xx][i]]){
			if(vis[g[xx][i]]!=3-p) return false;
			continue;
		}
		if (!dfs(g[xx][i],3-p)) return false;
	}
	return true;
}
int check(int xx){
	for (int i=0;i<n;i++) g[i].clear();
	memset (vis,0,sizeof(vis));
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			if (dist[i][j]>xx){
				g[i].push_back(j);
				g[j].push_back(i);  
			}
	int ans=1;
	for (int i=0;i<n;i++){
		if (!vis[i]){
			if (!dfs(i,1))
				return -1;
			ans=ans*2%MOD;
		}
	}
	return ans;
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++) cin>>x[i]>>y[i];
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			dist[i][j]=dist[j][i]=abs(x[i]-x[j])+abs(y[i]-y[j]);
	int r=2e4,l=0;
	while (r>l){
		int mid=(l+r)/2;
		int o=check(mid);
		if (o!=-1) r=mid,res=o;
		else l=mid+1;
	}
	cout<<r<<endl<<res;
	return 0;
}