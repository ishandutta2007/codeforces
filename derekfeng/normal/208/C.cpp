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
typedef pair<int,int> pii;
int n,m;
int dist[103];
priority_queue <pii,vector <pii>,greater <pii> > q;
vector <int> g[103];
vector <int> v;
bool vis[103];
ll dp[103][3];
ll ans1=-1,ans2=-1,ans3=-1;
int main(){
	cin>>n>>m;
	fill (dist,dist+103,1e9);
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);  
	}
	dist[1]=0;
	q.push(pii(0,1));
	while (!q.empty()){
		int x=q.top().second;
		q.pop();
		if (vis[x]) continue;
		vis[x]=1;
		v.push_back(x); 
		for (int i=0;i<g[x].size();i++)
			if (dist[g[x][i]]>dist[x]+1){
				dist[g[x][i]]=dist[x]+1;
				q.push(pii(dist[g[x][i]],g[x][i])); 
			}
	}
	for (int i=1;i<=n;i++){
		memset (dp,0,sizeof(dp));
		dp[1][0]=1;
		for (int j=1;j<v.size();j++){
			int x=v[j];
			for (int k=0;k<g[x].size();k++)
				if (dist[g[x][k]]==dist[x]-1){
					if (g[x][k]==i){
						dp[x][1]+=dp[g[x][k]][0];
						dp[x][2]+=dp[g[x][k]][1];
					}
					if (x==i){
						dp[x][1]+=dp[g[x][k]][0];
					}
					if (g[x][k]!=i && x!=i){
						dp[x][0]+=dp[g[x][k]][0];
						dp[x][1]+=dp[g[x][k]][1];
						dp[x][2]+=dp[g[x][k]][2];
					}
				}
		}
		if (ans1==-1){
			ans1=dp[n][0],ans2=dp[n][1],ans3=dp[n][2];
		}
		else if ((ans2+ans3*2)<(dp[n][1]+dp[n][2]*2)){
			ans1=dp[n][0],ans2=dp[n][1],ans3=dp[n][2];
		}
	}
	printf ("%.12lf",double(ans2+ans3*2)/double(ans1+ans2+ans3));
	return 0;
}