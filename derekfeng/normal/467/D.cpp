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
typedef pair<ll,ll> pii;
#define A first
#define B second
char low(char c){
	if (c<='Z' && c>='A') return c-'A'+'a';
	return c;
}
void low(string &s){
	for (int i=0;i<int(s.size());i++) s[i]=low(s[i]);
}
pii operator + (pii a,pii b){
	return pii(a.A+b.A,a.B+b.B);
}
pii score(string s){
	ll cnt=0;
	for (char c:s) cnt+=(c=='r');
	return pii(cnt,ll(s.size()));
}
unordered_map<string,int>strings;
int N,M;
int V;
const int MAXM=1e5+20;
const int MAXN=1e5+20;
int essay[MAXM];
const int MAXV=MAXM+2*MAXN;
vector <int> adj[MAXV];
pair <pii,int> vals[MAXV];
pii dp[MAXV];
const pii BAD(-1,-1);
int getstr(){
	string s;
	cin>>s;
	low(s);
	if (strings.count(s)) return strings[s];
	vals[V]=make_pair(score(s),V);
	strings[s]=V;
	return V++;
}
void dfs(int a,pii v){
	if (dp[a]!=BAD) return;
	dp[a]=v;
	for (int i:adj[a]) dfs(i,v);
}
int main(){
	V=0;
	cin>>M;
	for (int i=0;i<M;i++){
		essay[i]=getstr();
	}
	cin>>N;
	for (int i=0;i<N;i++){
		int l=getstr();
		int r=getstr();
		adj[r].push_back(l);
	}
	sort (vals,vals+V);
	for (int i=0;i<V;i++) dp[i]=BAD;
	for (int i=0;i<V;i++){
		int a=vals[i].B;
		pii v=vals[i].A;
		if (dp[a]==BAD) dfs(a,v);
	}
	pii res(0,0);
	for (int i=0;i<M;i++) res=res+dp[essay[i]];
	cout<<res.A<<" "<<res.B<<"\n";
}