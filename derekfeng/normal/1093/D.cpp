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
const ll MOD=998244353;
ll pw[300004];
ll col[300004];
ll t,n,m,num[3],ans;
vector <ll> g[300004];
bool okay;
void dfs(ll x,ll l){
	if (col[x]) return;
	num[l]++;
	col[x]=l;
	for (ll i=0;i<g[x].size();i++){
		if (col[g[x][i]] && (col[g[x][i]]+l)%2==0) okay=0; 
		dfs(g[x][i],3-l);
	}
}
int main(){
	pw[0]=1;
	for (ll i=1;i<300004;i++) pw[i]=pw[i-1]*2%MOD;
	cin>>t;
	while (t--){
		ans=1; 
		okay=1;
		cin>>n>>m;
		for (ll i=1;i<=n;i++){
			col[i]=0;
			g[i].clear();
		}
		while (m--){
			ll x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);  
		}
		for (ll i=1;i<=n;i++){
			if (col[i]) continue;
			num[1]=0,num[2]=0;
			dfs(i,1);
			ans=ans*((pw[num[1]]+pw[num[2]])%MOD)%MOD;
		}
		if (okay)cout<<ans<<endl;
		else cout<<"0\n";
	}
}