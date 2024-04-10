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
vector<int> G[1000005];
vector<int> ans;
vector<pii> ans2;
ll TO,sum[1000005],temp[1000005];
int ROOT;
int dfs(int v,int par){
	sum[v]=temp[v];
	int have=-1;
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u==par)continue;
		int cur=dfs(u,v);
		if(cur!=-1)have=cur;
		sum[v]+=sum[u];
	}
	if(v==ROOT)return -1;
	if(have!=-1){
		if(sum[v]==TO+TO)ans2.push_back(MP(have,v));
		return have;
	}
	if(sum[v]==TO){
		ans.push_back(v);
		return v;
	}else return -1;
}
int main(){
	int n,v;
	scanf("%d",&n);
	rep(k,n){
		scanf("%d%I64d",&v,&temp[k]);v--;
		if(v!=-1){
			G[k].push_back(v);
			G[v].push_back(k);
		}else ROOT=k;
		TO+=temp[k];
	}
	if(TO%3!=0LL){
		printf("-1");
		return 0;
	}
	TO/=3;
	dfs(ROOT,-1);
	if(ans.size()<2){
		if(!ans2.empty())printf("%d %d",ans2[0].first+1,ans2[0].second+1);
		else printf("-1");
	}else printf("%d %d",ans[0]+1,ans[1]+1);
	return 0;
}