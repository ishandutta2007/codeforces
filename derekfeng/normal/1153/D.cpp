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
int n,dp[300004],num=0;
vector <int> g[300004];
int a[300004],par[300004];
void made_tree(int x){
	if (g[x].size()==0){
		dp[x]=1;
		num++;
		return;
	}
	if (a[x]==1){
		dp[x]=1e5;
		for (int i=0;i<g[x].size();i++){
			made_tree(g[x][i]);
			dp[x]=min(dp[x],dp[g[x][i]]);
		}
	}else{
		dp[x]=0;
		for (int i=0;i<g[x].size();i++){
			made_tree(g[x][i]);
			dp[x]+=dp[g[x][i]];
		}
	}
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=2;i<=n;i++){
		cin>>par[i];
		g[par[i]].push_back(i);
	}
	made_tree(1);
	cout<<num-dp[1]+1;
}