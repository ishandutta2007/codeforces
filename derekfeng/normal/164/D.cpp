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
int n,k;
long long x[1003],y[1003];
long long dist[1003][1003];
vector <int> g[1003];
int vis[1003];
bool dfs(int u,int k){
	if (u==n) return true;
	if (vis[u]) return dfs(u+1,k);
	for (int i=0;i<g[u].size();i++)
		k-=(!vis[g[u][i]]++);
	if (k>=0 && dfs(u+1,k)) return true;
	vis[u]=1;
	int t=k;
	for (int i=0;i<g[u].size();i++)
		k+=(!--vis[g[u][i]]);
	if (--k>=0 && k>t && dfs(u+1,k)) return true;
	vis[u]=0;
	return false;
}
bool check(long long h){
	for (int i=0;i<n;i++)
		vis[i]=0,g[i].clear();
	for (int i=0;i<n;i++)
		for (int j=i;j<n;j++)
			if (dist[i][j]>h){
				g[i].push_back(j);
				g[j].push_back(i); 
			}
	return dfs(0,k);
}
int main(){
	vector <int> hp,d;
	cin>>n>>k;
	for (int i=0;i<n;i++)
		cin>>x[i]>>y[i];
	for (int i=0;i<n;i++)
		for (int j=i;j<n;j++){
			long long nah=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			hp.push_back(nah);
			dist[i][j]=nah;
			dist[j][i]=nah;
		}
	sort (hp.begin(),hp.end());
	for (int i=0;i<hp.size();i++)
		if (i==0 || hp[i]!=hp[i-1])
			d.push_back(hp[i]);
	int l,r,mid;
	l=-1,r=d.size();
	while (r-l>1){
		mid=(r+l)/2;
		if (check(d[mid])) r=mid;
		else l=mid;
	}
	check(d[r]);
	for (int i=0;i<n;i++)
		if (vis[i]){
			cout<<i+1<<" ";
			k--;
		}
	for (int i=0;i<n && k;i++)
		if (!vis[i]){
			cout<<i+1<<" ";
			k--;
		}
	return 0;
}