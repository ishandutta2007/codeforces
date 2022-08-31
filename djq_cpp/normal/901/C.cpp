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
int st[300005],ssz;
bool hv[300005];
bool vis[300005];
int cnt,D[300005],minD[300005];
vector<int> G[300005];
int grp[300005];
int st_top(){
	return st[ssz-1];
}
void st_push(int v){
	st[ssz++]=v;
	hv[st_top()]=true;
}
void st_pop(){
	hv[st_top()]=false;
	ssz--;
}
void st_clear(){
	while(ssz){
		hv[st_top()]=false;
		ssz--;
	}
}
bool st_in(int v){
	return hv[v];
}
int st_kth(int id){
	return id>=ssz?-1:st[id];
}
void dfs(int v,int par){
	vis[v]=true;
	D[v]=minD[v]=++cnt;
	st_push(v);
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u==par)continue;
		if(!vis[u]){
			dfs(u,v);
			minD[v]=min(minD[v],minD[u]);
		}else if(st_in(u))minD[v]=min(minD[v],D[u]);
	}
	if(D[v]==minD[v])
	for(;;){
		int u=st_top();
		st_pop();
		grp[u]=v;
		if(u==v)break;
	}
}
int n,lp[300005],rp[300005];
int tol[300005],tor[300005];
vector<int> tp[300005];
void init(){
	rep1(k,n)if(!vis[k])dfs(k,0);
	rep1(k,n)tp[grp[k]].push_back(k);
	rep1(k,n+1){
		tol[k]=0;
		tor[k]=INF;
	}
	rep1(i,n){
		if(tp[i].size()==1)continue;
		int minv=INF,maxv=0;
		rep(j,tp[i].size()){
			minv=min(minv,tp[i][j]);
			maxv=max(maxv,tp[i][j]);
		}
		rep(j,tp[i].size()){
			lp[tp[i][j]]=minv;
			rp[tp[i][j]]=maxv;
		}
	}
	rep1(k,n){
		tol[k]=tol[k-1];
		if(rp[k]==k)tol[k]=max(tol[k],lp[k]+1);
	}
	for(int k=n;k>=1;k--){
		tor[k]=tor[k+1];
		if(lp[k]==k)tor[k]=min(tor[k],rp[k]-1);
	}
}
vector<int> qy[550][550];
ll ans[300005];
int ql[300005],qr[300005];
ll ca=0LL;
int main(){
	int m,q,u,v;
	scanf("%d%d",&n,&m);
	rep(k,m){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	init();
	scanf("%d",&q);
	int l=1,r=0;
	rep(k,q){
		scanf("%d%d",&ql[k],&qr[k]);
		qy[ql[k]/550][qr[k]/550].push_back(k);
	}
	rep(i,550)rep(j,550)rep(k,qy[i][j].size()){
		int id=qy[i][j][k];
		int cl=ql[id],cr=qr[id];
		while(r<cr){
			r++;ca+=r-max(l,tol[r])+1;
		}
		while(l<cl){
			ca-=min(r,tor[l])-l+1;l++;
		}
		while(l>cl){
			l--;ca+=min(r,tor[l])-l+1;
		}
		while(r>cr){
			ca-=r-max(l,tol[r])+1;r--;
		}
		ans[id]=ca;
	}
	rep(k,q)printf("%I64d\n",ans[k]);
	return 0;
}