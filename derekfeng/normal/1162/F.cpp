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
typedef long long ll;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
const ll MOD=998244353;
string s;int m;
ll ans=0;
vector <pii> g[2006];
int vis[2006],cnt,has[2006];
int dfs(int x,int now){
	vis[x]=now;
	has[x]=1;
	bool ok=1;
	for (int i=0;i<g[x].size();i++){
		if (vis[g[x][i].fi]!=-1){
			if (vis[g[x][i].fi]!=now^(g[x][i].se)) return 0;
		}
		if (!has[g[x][i].fi])
			ok&=dfs(g[x][i].fi,now^(g[x][i].se));
	}
	return ok;
}
int main(){
	cin>>s;m=s.size();s="0"+s;
	for (int i=1;i<m;i++){
		ll res=1;
		memset (vis,-1,sizeof(vis));
		memset (has,0,sizeof(has));
		for (int j=0;j<2006;j++) g[j].clear();
		for (int k=1,j=m;k<j;k++,j--)g[k].push_back(mkp(j,0)),g[j].push_back(mkp(k,0)); 
		for (int k=1,j=i;k<j;k++,j--)g[k+m].push_back(mkp(j+m,0)),g[j+m].push_back(mkp(k+m,0));  
		for (int j=m-i+1,k=1;j<=m;j++,k++){
			if (s[j]=='1') g[j].push_back(mkp(k+m,1)),g[k+m].push_back(mkp(j,1)); 
			if (s[j]=='0') g[j].push_back(mkp(k+m,0)),g[k+m].push_back(mkp(j,0));
		}
		for (int j=1;j<=m-i;j++) if (s[j]!='?')vis[j]=s[j]-'0';
		vis[1+m]=1; 
		if(!dfs(1+m,1)) res*=0;
		for (int j=1;j<=m-i && res>0;j++)if (!has[j] && vis[j]!=-1){
			if (!dfs(j,vis[j])) res*=0;
		}
		for (int j=1;j<=m+i && res>0;j++)if(!has[j]){
			if (!dfs(j,0)) res=0;
			else res=res*2%MOD;
		}
		ans=(ans+res)%MOD;
	}
	cout<<ans;
}