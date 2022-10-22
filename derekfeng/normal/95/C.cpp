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
typedef long long ll;
typedef pair<ll,ll> pii;
vector <pii> g[1003];
ll dist[1003][1003],t[1003],c[1003];
int n,m,sx,ex;
void dijkstra1(int x){
	priority_queue <pii,vector <pii>,greater<pii> > q;
	q.push(pii(0,x));
	dist[x][x]=0;
	while (!q.empty()){
		pii xx=q.top();
		q.pop();
		ll d=xx.first,to=xx.second;
		for (int i=0;i<g[to].size();i++)
			if (dist[x][g[to][i].first]>dist[x][to]+g[to][i].second){
				dist[x][g[to][i].first]=dist[x][to]+g[to][i].second;
				q.push(pii(dist[x][g[to][i].first],g[to][i].first)); 
			}
	}
}
int main(){
	for (int i=1;i<=1000;i++)
		for (int j=1;j<=1000;j++)
			dist[i][j]=1e18;
	cin>>n>>m>>sx>>ex;
	for (ll i=0;i<m;i++){
		ll x,y,w;
		cin>>x>>y>>w;
		g[x].push_back(pii(y,w));
		g[y].push_back(pii(x,w));  
	}
	for (int i=1;i<=n;i++)
		dijkstra1(i);
	for (int i=1;i<=n;i++)
		cin>>t[i]>>c[i]; 
	for (int i=1;i<=n;i++)
		g[i].clear();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			if (i==j) continue;
			if (dist[i][j]<=t[i])
				g[i].push_back(pii(j,c[i])); 
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			dist[i][j]=1e18;
	dijkstra1(sx);
	if (dist[sx][ex]==1e18) cout<<"-1";
	else cout<<dist[sx][ex];
	return 0;
}