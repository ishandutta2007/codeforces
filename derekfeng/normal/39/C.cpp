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
int n;
int dp[4005][4005];
int id[4005][4005];
int low[4005],high[4005];
map <int,int> mp;
vector <int> v[4005];
int dfs(int l,int r){
	if (dp[l][r]!=-1) return dp[l][r];
	if (l==r) return dp[l][r]=0;
	int cur=0;
	if (id[l][r]!=-1) cur=1;
	int ans=cur+dfs(l,r-1);
	for (int i=0;i<v[r].size();i++){
		int x=low[v[r][i]];
		if (x<=l) continue;
		int res=cur+dfs(l,x)+dfs(x,r);
		ans=max(ans,res);
	}
	return dp[l][r]=ans;
}
vector <int> anss;
void dfs1(int l,int r){
	if (l==r) return;
	int cur=0;
	if (id[l][r]!=-1){
		cur=1;
		anss.push_back(id[l][r]+1); 
	}
	if (dp[l][r]==cur+dp[l][r-1]){
		dfs1(l,r-1);
		return;
	}
	for (int i=0;i<v[r].size();i++){
		int x=low[v[r][i]];
		if (x<=l) continue;
		if (dp[l][r]==cur+dp[l][x]+dp[x][r]){
			dfs1(l,x);
			dfs1(x,r);
			return;
		}
	}
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		int c,r;
		scanf ("%d%d",&c,&r);
		low[i]=c-r;
		high[i]=c+r;
		mp[low[i]]=mp[high[i]]=0;
	}
	int cnt=0;
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		(it->second)=cnt;
		cnt++;
	}
	for (int i=0;i<n;i++){
		low[i]=mp[low[i]];
		high[i]=mp[high[i]];
		v[high[i]].push_back(i); 
	}
	for (int i=0;i<cnt;i++) for (int j=0;j<cnt;j++) id[i][j]=-1;
	for (int i=0;i<n;i++) id[low[i]][high[i]]=i;
	for (int i=0;i<cnt;i++) for (int j=0;j<cnt;j++) dp[i][j]=-1;
	int ans=dfs(0,cnt-1);
	cout<<ans<<"\n";
	dfs1(0,cnt-1);
	sort (anss.begin(),anss.end());
	for (int i=0;i<anss.size();i++) cout<<anss[i]<<" ";
}