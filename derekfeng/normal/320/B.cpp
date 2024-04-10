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
typedef pair<int,int> pii;
pii path[103];
vector <int> g[103]; 
bool dfs(int a,int b,bool vis[103]){
	if (vis[a])  return false;
	vis[a]=1;
	for (int i=0;i<g[a].size();i++){
		if (g[a][i]==b) return true;
		if (dfs(g[a][i],b,vis)) return true;
	}
	return false;
}
int main(){
	int n,cnt=1;
	cin>>n;
	while (n--){
		char c;
		cin>>c;
		int l,r;
		cin>>l>>r;
		if (c=='1'){
			path[cnt]=pii(l,r);
			for (int i=1;i<cnt;i++){
				if ((path[i].first<l && l<path[i].second)||(path[i].first<r && r<path[i].second)) g[cnt].push_back(i);
				if ((l<path[i].first && path[i].first<r)||(l<path[i].second && path[i].second<r)) g[i].push_back(cnt);
			}
			cnt++;
		}
		if (c=='2'){
			bool vis[103];
			memset (vis,0,sizeof(vis));
			if (dfs(l,r,vis)) puts("YES");
			else puts("NO"); 
		}
	}
	return 0;
}