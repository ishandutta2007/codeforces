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
int n,m,d;
bool stane[100004];
vector <int> g[100004];
int dist[100004],dist1[100004],dist2[100004];
bool vis[100004];
int second_big(int a,int b,int c){
	int qq[3];
	qq[0]=a,qq[1]=b,qq[2]=c;
	sort (qq,qq+3);
	return qq[1];
}
void make_down_dist(int x){
	vis[x]=1;
	if (stane[x]) dist[x]=0,dist2[x]=-1;
	else dist[x]=-1,dist2[x]=-1;
	for (int i=0;i<g[x].size();i++) if (!vis[g[x][i]]){
		make_down_dist(g[x][i]);
		if (dist[g[x][i]]==-1) continue;
		int sebig=second_big(dist[x],dist2[x],dist[g[x][i]]+1);
		dist[x]=max(dist[x],dist[g[x][i]]+1);
		dist2[x]=sebig;
	}
}
void make_up_dist(int x,int now){
	dist1[x]=now;
	vis[x]=1;
	int bigst=dist[x],sebig=dist2[x];
	if (now==-1){
		if (bigst==-1){
			for (int i=0;i<g[x].size();i++) if (!vis[g[x][i]]) make_up_dist(g[x][i],-1);
		}else{
			for (int i=0;i<g[x].size();i++) if (!vis[g[x][i]]){
				if (dist[g[x][i]]!=-1 && dist[g[x][i]]+1==bigst) make_up_dist(g[x][i],(sebig==-1)?-1:sebig+1); 
				else make_up_dist(g[x][i],bigst+1);
			}
		}
	}else{
		for (int i=0;i<g[x].size();i++) if (!vis[g[x][i]]){
			if (dist[g[x][i]]!=-1 && dist[g[x][i]]+1==bigst)make_up_dist(g[x][i],max(now,sebig)+1);
			else make_up_dist(g[x][i],max(now,bigst)+1);
		}
	}
}
int main(){
	scanf ("%d%d%d",&n,&m,&d);
	while (m--){
		int x;
		scanf ("%d",&x);
		stane[x]=1;
	}
	for (int i=0;i<n-1;i++){
		int x,y;
		scanf ("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int ans=0;
	make_down_dist(1);
	memset (vis,0,sizeof(vis));
	make_up_dist(1,-1);
	for (int i=1;i<=n;i++){
		int sum=dist[i]==-1?0:dist[i];
		sum=max(dist1[i]==-1?0:dist1[i],sum);
		if (sum<=d)
			ans++;
	}
	cout<<ans;
}