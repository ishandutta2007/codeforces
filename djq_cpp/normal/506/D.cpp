//Codeforces 506D
//author: djq_cpp
//Date:Mar/18/2017~?
//ncolordfs
//
//vectorO(n) 
//2
//	>=sqrt(n) 
//	<=sqrt(n)
//	*O()=O() 
//
//	querycolorO(log n) 
//	color<=sqrt(n)
//	O(n sqrt(n) log n) 
//
//	(size<=sqrt(n))
//	
//	setqueryO(log n)
//	=S(size^2)
//			<=S(size*sqrt(n))
//			=S(size)*sqrt(n)
//          =O(n sqrt(n))
//	O(n sqrt(n))*O(log n)
//	     =O(n sqrt(n) log n)
//=O(n sqrt(n) log n)
//n=10^5
//100000*300*20
//	6*10^8
//O2vector&sort&lower_bound2*10^8,48*10^8
// 
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
const int INF=1e9+7,LIM=450;
int n,m,Q;
//size1sortedsizesize 
vector<vector<int> > grp_L,grp_S;
//(sorted)
vector<int> have[100005];
// 
vector<vector<int> > G[100005];
//dfsvisit
vector<bool> visit[100005];
//querysorted
//query 
// 
pair<pii,int> query[100005]; 
//query
int ans[100005]; 
//
vector<pii> EDGES[100005]; 
// 
int getid(int c,int v){
	int pos=lower_bound(have[c].begin(),have[c].end(),v)-have[c].begin();
	if(pos>=have[c].size()||have[c][pos]!=v)return -1;
	return pos;
}
//
	//have
	void init_have(int c){
		rep(k,EDGES[c].size()){
			have[c].push_back(EDGES[c][k].first);
			have[c].push_back(EDGES[c][k].second);
		}
		sort(have[c].begin(),have[c].end());
		have[c].resize(unique(have[c].begin(),have[c].end())-have[c].begin());
	}
	//Graph
	void init_graph(int c){
		G[c].resize(have[c].size(),vector<int>());
		rep(k,EDGES[c].size()){
			int u=getid(c,EDGES[c][k].first),v=getid(c,EDGES[c][k].second);
			G[c][u].push_back(v);
			G[c][v].push_back(u);
		}
	}
	//query
	void init_query(){
		rep(k,Q){
			query[k].second=k;
			if(query[k].first.first>query[k].first.second)
			swap(query[k].first.first,query[k].first.second);
		}
		sort(query,query+Q);
	}
	// 
		//v 
		void dfs(int c,int v,vector<int> &S){
			S.push_back(have[c][v]);
			visit[c][v]=true;
			rep(k,G[c][v].size()){
				int u=G[c][v][k];
				if(visit[c][u])continue;
				dfs(c,u,S);
			}
		}
		//
		void getgrp(int c){
			visit[c].resize(have[c].size(),false);
			rep(k,have[c].size()){
				vector<int> S;
				if(!visit[c][k])dfs(c,k,S);
				sort(S.begin(),S.end()); 
				if(S.size()>LIM)grp_L.push_back(S);
				else grp_S.push_back(S);
			}
		}
		// 
		void getgrp(){
			rep1(k,m)getgrp(k);
		}
	// 
	void init(){
		rep1(k,m){
			init_have(k);
			init_graph(k);
		}
		getgrp();
		init_query();
	}
	
//large
	//
	bool IN_grp(int v,int Gid){
		vector<int>::iterator it=lower_bound(grp_L[Gid].begin(),grp_L[Gid].end(),v);
		return it!=grp_L[Gid].end()&&(*it)==v;
	}
	//query
	void solve_L(int Qid){
		int u=query[Qid].first.first,v=query[Qid].first.second;
		rep(k,grp_L.size())if(IN_grp(u,k)&&IN_grp(v,k))ans[query[Qid].second]++;
	}
	//query
	void solve_L(){
		rep(k,Q){
			if(k>0&&query[k].first==query[k-1].first)continue;
			solve_L(k);
		}
	} 
//small
	//uvqueryidsorted id 
	int getQ(int u,int v){
		int pos=lower_bound(query,query+Q,MP(MP(u,v),-1))-query;
		if(pos==Q||query[pos].first.first!=u||query[pos].first.second!=v)return -1; 
		return pos;
	}
	//query
	void solve_S(){
		rep(k,grp_S.size()){
			rep(i,grp_S[k].size())rep(j,i){
				int q=getQ(grp_S[k][j],grp_S[k][i]);
				if(q!=-1)ans[query[q].second]++; 
			}
		}
	}
//query
void solve_Q(){
	solve_L();
	solve_S();
	for(int k=1;k<Q;k++)
	if(query[k].first==query[k-1].first)
	ans[query[k].second]=ans[query[k-1].second];
} 
int main(){
	scanf("%d%d",&n,&m);
	rep(k,m){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		EDGES[c].push_back(MP(u,v));
	}
	scanf("%d",&Q);
	rep(k,Q)scanf("%d%d",&query[k].first.first,&query[k].first.second);
	init();
	solve_Q();
	rep(k,Q)printf("%d\n",ans[k]);
	return 0;
}