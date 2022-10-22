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
#define mkp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;
ll dp[200004][2][2],ans=0;
vector <pii> g[200004];
int n;
bool vis[200005];
void dfs(int x){
	vis[x]=1;
	for (int i=0;i<g[x].size();i++) if (!vis[g[x][i].fi]){
		int y=g[x][i].fi,z=g[x][i].se;
		dfs(y);
		ans+=dp[x][0][1-z]*(dp[y][0][z]+1)+dp[x][0][z]*(dp[y][0][z]+1+dp[y][1][z]+dp[y][0][1-z])+dp[x][1][z]*(dp[y][0][z]+1)+dp[x][0][z]*(dp[y][0][z]+1);
		dp[x][0][z]+=dp[y][0][z]+1;
		dp[x][1][z]+=dp[y][1][z]+dp[y][0][1^z];
	}
	ans+=dp[x][0][0]*2+dp[x][0][1]*2+dp[x][1][0]+dp[x][1][1];
}
int main(){
	cin>>n;
	for (int i=0;i<n-1;i++){
		int x,y,c;
		scanf ("%d%d%d",&x,&y,&c);
		g[x].push_back(mkp(y,c));
		g[y].push_back(mkp(x,c));
	}
	dfs(1);
	cout<<ans;
}