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
int p[1003];
bool vis[1003];
int dfs(int x){
	if (vis[x]){return x;}
	vis[x]=1;
	return dfs(p[x]);
}
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>p[i];
	for (int i=1;i<=n;i++){
		memset (vis,0,sizeof(vis));
		cout<<dfs(i)<<" ";
	}
	return 0;
}