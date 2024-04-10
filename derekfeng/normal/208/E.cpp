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
int n,m;
vector <int> g[100004];
vector <int> ans[100004];
int lb[100004],rb[100004],cnt,par[19][100004],dp[100004];
void dfs(int x,int paret,int dep){
	par[0][x]=paret;
	cnt++; 
	lb[x]=cnt;
	dp[x]=dep;
	ans[dep].push_back(cnt);
	for (int i=0;i<g[x].size();i++) dfs(g[x][i],x,dep+1);
	cnt++;
	rb[x]=cnt;
}
int upd(int x,int p){
	int res=x;
	for (int i=0;i<19;i++) if (res!=-1 && ((1<<i)&p)) res=par[i][res];	
	return res;
}
vector <int> root;
int main(){
	memset (lb,-1,sizeof(lb));
	cin>>n;
	for (int i=1;i<=n;i++){
		int x;
		scanf ("%d",&x);
		g[x].push_back(i);
		if (x==0) root.push_back(i); 
	}
	cin>>m;
	for (int i=0;i<root.size();i++) dfs(root[i],-1,0);
	for (int i=1;i<19;i++)
		for (int j=1;j<=n;j++){
			if (par[i-1][j]==-1){
				par[i][j]=-1;
				continue;
			}
			par[i][j]=par[i-1][par[i-1][j]];
		}
	while (m--){
		int x,p;
		scanf ("%d%d",&x,&p);
		int p_c=upd(x,p); 
		if (p_c==-1){
			printf("0\n");
			continue;
		}
		int a1=upper_bound(ans[dp[x]].begin(),ans[dp[x]].end(),rb[p_c])-ans[dp[x]].begin();
		int a2=lower_bound(ans[dp[x]].begin(),ans[dp[x]].end(),lb[p_c])-ans[dp[x]].begin();
		printf("%d\n",a1-a2-1);
	}
}