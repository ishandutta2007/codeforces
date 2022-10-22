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
typedef long long ll;
ll ans=1;
const ll MOD=998244353;
ll num[200004];
int n;
vector <int> g[200004];
void dfs(int x,int parts){
	int nd=1;
	for (int i=0;i<g[x].size();i++) if (g[x][i]!=parts){
		dfs(g[x][i],x);
		nd++;
	}
	if (x==1) nd--;
	ans=(ans*num[nd])%MOD;
}
int main(){
	cin>>n;
	for (int i=0;i<n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	num[1]=1;
	for (int i=2;i<=n;i++) num[i]=(num[i-1]*i)%MOD;
	dfs(1,-1);
	cout<<(ans*n)%MOD;
}