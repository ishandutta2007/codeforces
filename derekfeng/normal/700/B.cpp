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
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200004];
int vis[200004];
vector <int> g[200004];
ll ans=0;
int n,k,r;
int dfs(int x,int par){
	int now=vis[x];
	for (int i=0;i<g[x].size();i++) if (g[x][i]!=par) now+=dfs(g[x][i],x);
	while (now*2>r) r-=2,now-=2;
	ans+=now;
	return now;
}
int main(){
	cin>>n>>k;
	r=k*2;
	for (int i=0;i<r;i++){
		int x;scanf ("%d",&x);
		vis[x]=1;
	}
	for (int i=0;i<n-1;i++){
		int x,y;
		scanf ("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,-1);
	cout<<ans;
}