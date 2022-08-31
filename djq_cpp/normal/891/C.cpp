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
vector<int> E[500005];
pair<int,pii> ev[500005];
int pre[500005],sz[500005];
vector<vector<int> > Q[500005];
vector<bool> ans[500005];
vector<pii> nd[500005];
struct DSU{
	int pre[5000005],sz[500005];
	void dsu_clear(int v){
		pre[v]=v;
		sz[v]=1;
	}
	void dsu_init(int n){
		rep1(i,n)dsu_clear(i);
	}
	int dsu_root(int v){
		return pre[v]==v?v:pre[v]=dsu_root(pre[v]);
	}
	bool dsu_unite(int u,int v){
		u=dsu_root(u);v=dsu_root(v);
		if(u==v)return false;
		if(sz[u]<sz[v])swap(u,v);
		pre[v]=u;
		sz[u]+=sz[v];
		return true;
	}
}G,cg;
int main(){
	int n,m,q,maxv=0,cnt,v;
	scanf("%d%d",&n,&m);
	rep1(i,m){
		scanf("%d%d%d",&ev[i].second.first,&ev[i].second.second,&ev[i].first);
		E[ev[i].first].push_back(i);
		maxv=max(maxv,ev[i].first);
	}
	scanf("%d",&q);
	rep(i,q){
		scanf("%d",&cnt);
		vector<int> cur;
		rep(j,cnt){
			scanf("%d",&v);
			cur.push_back(v);
		}
		rep(j,cur.size()){
			int cl=ev[cur[j]].first;
			if(Q[cl].empty()||!Q[cl].back().empty()){
				nd[i].push_back(MP(cl,Q[cl].size()));
				Q[cl].push_back(vector<int>());
			}
		}
		rep(j,cur.size())Q[ev[cur[j]].first].back().push_back(cur[j]);
	}
	G.dsu_init(n);
	rep1(i,maxv){
		rep(j,Q[i].size()){
			rep(k,Q[i][j].size()){
				int ce=Q[i][j][k];
				cg.dsu_clear(G.dsu_root(ev[ce].second.first));
				cg.dsu_clear(G.dsu_root(ev[ce].second.second));
			}
			bool ok=true;
			rep(k,Q[i][j].size()){
				int ce=Q[i][j][k];
				if(!cg.dsu_unite(G.dsu_root(ev[ce].second.first),G.dsu_root(ev[ce].second.second))){
					ok=false;break;
				}
			}
			ans[i].push_back(ok);
		}
		rep(j,E[i].size())G.dsu_unite(ev[E[i][j]].second.first,ev[E[i][j]].second.second);
	}
	rep(i,q){
		bool ok=true;
		rep(j,nd[i].size())
		if(!ans[nd[i][j].first][nd[i][j].second]){
			ok=false;break;
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}