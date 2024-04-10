#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
vector<int> G[200005];
ll dp[200005][2];
int vis[200005];
int cnt=0;
ll power(int T){
	if(T==0)return 1LL;
	ll pre=power(T>>1);
	pre=pre*pre%INF;
	if(T&1)pre=(pre+pre)%INF;
	return pre;
}
bool dfs(int v,int par){
	vis[v]=1;
	cnt++;
	bool ans=false;
	rep(k,G[v].size()){
		int u=G[v][k];
		if(vis[u]==0&&dfs(u,v))ans=true;
		else if(vis[u]==1&&u!=par)ans=true;
	}
	vis[v]=-1;
	return ans;
}
map<int,int> xs,ys;
int main(){
	int n,x,y;
	scanf("%d",&n);
	rep(k,n){
		scanf("%d%d",&x,&y);
		int cx=xs.find(x)==xs.end()?(xs[x]=cnt++):xs[x];
		int cy=ys.find(y)==ys.end()?(ys[y]=cnt++):ys[y];
		G[cx].push_back(cy);
		G[cy].push_back(cx);
	}
	n=cnt;
	ll ans=1LL;
	rep(k,n)if(!vis[k]){
		cnt=0;
		if(dfs(k,-1))ans=ans*power(cnt)%INF;
		else ans=ans*(power(cnt)-1+INF)%INF;
	}
	printf("%I64d\n",ans);
	return 0;
}