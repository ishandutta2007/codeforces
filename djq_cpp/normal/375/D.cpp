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
vector<int> G[100005];
int n,col[100005],rc[100005];
int cntc[100005],res[100005];
vector<pair<pii,int> > qy[320][320];
int cnt,bg[100005],ed[100005];
int qk[100005],ans[100005];
void dfs(int v,int par){
	rc[cnt]=col[v];
	bg[v]=cnt++;
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u!=par)dfs(u,v);
	}
	ed[v]=cnt;
}
int main(){
	int q,u,v;
	scanf("%d%d",&n,&q);
	rep1(k,n)scanf("%d",&col[k]);
	rep(k,n-1){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	rep(k,q){
		scanf("%d%d",&u,&v);
		qk[k]=v;
		qy[bg[u]/317][ed[u]/317].push_back(MP(MP(bg[u],ed[u]),k));
	}
	int cl=0,cr=0;
	rep(i,317)rep(j,317)rep(k,qy[i][j].size()){
		int l=qy[i][j][k].first.first,r=qy[i][j][k].first.second;
		while(cl>l){
			cl--;cntc[rc[cl]]++;res[cntc[rc[cl]]]++;
		}
		while(cl<l){
			res[cntc[rc[cl]]]--;cntc[rc[cl]]--;cl++;
		}
		while(cr<r){
			cntc[rc[cr]]++;res[cntc[rc[cr]]]++;cr++;
		}
		while(cr>r){
			cr--;res[cntc[rc[cr]]]--;cntc[rc[cr]]--;
		}
		int qid=qy[i][j][k].second;
		ans[qid]=res[qk[qid]];
	}
	rep(k,q)printf("%d\n",ans[k]);
	return 0;
}