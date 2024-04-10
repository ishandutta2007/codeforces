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
vector <int> g[400004];
bool vis[400004];
void dfs(int x) {
	if (vis[x]) return;
	vis[x]=1;
	for (int i=0; i<g[x].size(); i++)
		dfs(g[x][i]);
}
int main() {
	int n,m,q,cnt=0;
	cin>>n>>m>>q;
	for (int i=0; i<q; i++) {
		int x,y;
		cin>>x>>y;
		y+=n;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1; i<=n+m; i++)
		if (!vis[i]) {
			dfs(i);
			cnt++;
		}
	cout<<cnt-1;
	return 0;
}