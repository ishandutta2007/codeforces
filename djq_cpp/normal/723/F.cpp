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
vector<int> parts;
vector<int> adj[200005],G2[200005];
bool vis[200005],cst;
int s,t,canS[200005],canT[200005];
void dfs(int x,int id){
	vis[x]=true;
	rep(k,adj[x].size()){
		int v=adj[x][k];
		if(v==s)canS[id]=x;
		if(v==t)canT[id]=x;
		if(v==s||v==t||vis[v])continue;
		G2[x].push_back(v);
		dfs(v,id);
	}
}
void getall(int n){
	rep(k,n)canS[k]=canT[k]=-1;
	int id=0;
	rep(k,n)if(!vis[k]&&k!=s&&k!=t){
		parts.push_back(k);
		canS[k]=canT[k]=-1;
		dfs(k,id++);
	}
}
bool chkans(int n,int lim1,int lim2){
	int Ssz=0,Tsz=0;
	vector<int> both;
	rep(k,parts.size()){
		if(canS[k]==-1&&canT[k]==-1)return false;
		if(canS[k]==-1){
			Tsz++;
			G2[t].push_back(canT[k]);
			continue;
		}
		if(canT[k]==-1){
			Ssz++;
			G2[s].push_back(canS[k]);
			continue;
		}
		both.push_back(k);
	}
	int pos=0;
	if(both.empty()){
		if(cst){
			G2[s].push_back(t);
			Ssz++;Tsz++;
		}else return false;
	}else{
		pos=1;
		G2[s].push_back(canS[both[0]]);Ssz++;
		G2[t].push_back(canT[both[0]]);Tsz++;
	}
	if(Ssz>lim1||Tsz>lim2)return false;
	while(Ssz<lim1&&pos<both.size()){
		G2[s].push_back(canS[both[pos++]]);
		Ssz++;
	}
	while(Tsz<lim2&&pos<both.size()){
		G2[t].push_back(canT[both[pos++]]);
		Tsz++;
	}
	return pos==both.size();
}
void vin(int &x){
	scanf("%d",&x);x--;
}
void vout(int x){
	printf("%d",x+1);
}
int main(){
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	rep(k,m){
		vin(x);vin(y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vin(s);vin(t);scanf("%d%d",&x,&y);
	rep(k,adj[s].size())if(adj[s][k]==t)cst=true;
	getall(n);
	if(chkans(n,x,y)){
		puts("Yes");
		rep(i,n)rep(j,G2[i].size()){
			vout(i);
			putchar(' ');
			vout(G2[i][j]);
			putchar('\n');
		}
	}else puts("No");
	return 0;
}