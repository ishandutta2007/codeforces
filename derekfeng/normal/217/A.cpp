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
#include <numeric>
#include <memory>
#include <cstring> 
#include <fstream>
#include <assert.h>
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
int n,ans;
int vis[2003],good[2003];
vector <int> g[2003];
void dfs(int x){
	good[x]=1;
	for (int i=0;i<g[x].size();i++)if (!good[g[x][i]])
		dfs(g[x][i]);
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		int x,y;cin>>x>>y;y+=1000;
		g[x].push_back(y);
		g[y].push_back(x);  
		vis[x]=1,vis[y]=1;
	}
	for (int i=0;i<=2000;i++){
		if (!vis[i] || good[i]) continue;
		dfs(i);
		ans++;
	}
	cout<<ans-1;
}