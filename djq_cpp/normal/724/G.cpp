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
const int MOD=1e9+7,INV2=5e8+4;
template<typename T>
T lowbit(T x){
	return x&(-x);
}
struct basis{
	ll have; 
	vector<ll> vv,lb;
	void clear(){
		have=0LL;
		vv.clear();
		lb.clear();
	}
	int size(){
		return vv.size();
	}
	void insert(ll nv){
		have|=nv;
		rep(k,vv.size())
		if(nv&lb[k])nv^=vv[k];
		if(nv==0LL)return;
		vv.push_back(nv);
		lb.push_back(lowbit(nv));
	}
}bas;
vector<pair<int,ll> > G[100005];
bool vis[100005];
ll dat[100005];
ll pw2[100005];
void precalc(){
	pw2[0]=1LL;
	rep1(k,5000)pw2[k]=pw2[k-1]*2%MOD;
}
vector<int> cur;
void dfs(int v,ll cc){
	if(vis[v]){
		bas.insert(cc^dat[v]);
		return;
	}
	cur.push_back(v);
	vis[v]=true;
	dat[v]=cc;
	rep(k,G[v].size())dfs(G[v][k].first,cc^G[v][k].second);
}
int main(){
	int n,m;
	ll ans=0LL;
	precalc();
	scanf("%d%d",&n,&m);
	rep(k,m){
		int u,v;
		ll w;
		scanf("%d%d%I64d",&u,&v,&w);
		G[u].push_back(MP(v,w));
		G[v].push_back(MP(u,w));
	}
	rep1(i,n)if(!vis[i]){
		cur.clear();
		bas.clear();
		dfs(i,0LL);
		rep(j,64){
			if(bas.have>>j&1LL)
			ans+=ll(cur.size()-1)*cur.size()%MOD*INV2%MOD*pw2[bas.size()-1]%MOD*pw2[j]%MOD;
			else{
				int c1=0,c2=0;
				rep(k,cur.size())
				if(dat[cur[k]]>>j&1LL)c1++;
				else c2++;
				ans+=ll(c1)*c2%MOD*pw2[bas.size()]%MOD*pw2[j]%MOD;
			}
			if(ans>=MOD)ans-=MOD;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}