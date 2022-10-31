//This disgusting code is wriiten by Juruo D0zingbear
//Please don't hack me! 0v0 <3
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#define LL long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 19260817
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}

// cf IO: I64d
// atcoder IO: 
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=50005;
const int Sqr=150;
set<int> smallf[Maxn],bigf[Maxn];
vector<int> G[Maxn];
int cnt[Maxn],deg[Maxn];
bool f[Maxn];
int n,m,q,o;
void Update(int x){
	cnt[x]=0;
	for (set<int>::iterator it=smallf[x].begin();it!=smallf[x].end();it++){
		if (f[(*it)]) cnt[x]++;
	}
	for (set<int>::iterator it=bigf[x].begin();it!=bigf[x].end();it++){
		if (f[(*it)]) cnt[x]++;
	}
}
void Update2(int x){
	cnt[x]=0;
	for (set<int>::iterator it=smallf[x].begin();it!=smallf[x].end();it++){
		if (f[(*it)]) cnt[x]++;
		int vv=*it;
		smallf[vv].erase(x);
		bigf[vv].insert(x);
	}
	for (set<int>::iterator it=bigf[x].begin();it!=bigf[x].end();it++){
		if (f[(*it)]) cnt[x]++;
		int vv=*it;
		smallf[vv].erase(x);
		bigf[vv].insert(x);
	}
}
void Update3(int x){
	for (set<int>::iterator it=smallf[x].begin();it!=smallf[x].end();it++){
		int vv=*it;
		smallf[vv].insert(x);
		bigf[vv].erase(x);
	}
	for (set<int>::iterator it=bigf[x].begin();it!=bigf[x].end();it++){
		int vv=*it;
		smallf[vv].insert(x);
		bigf[vv].erase(x);
	}
}
int main(){
	scanf("%d %d %d",&n,&m,&q);
	scanf("%d",&o);
	for (int i=0;i<o;i++){
		int x;
		scanf("%d",&x);
		f[x]=true;
	}
	for (int i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		deg[u]++;
		deg[v]++;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<G[i].size();j++){
			int v=G[i][j];
			if (G[v].size()>Sqr){
				bigf[i].insert(v);
			}
			else{
				smallf[i].insert(v);
			}
		}
		if (G[i].size()>Sqr) Update(i);
	}
	//cerr<<123<<endl;
	
	for (int i=0;i<q;i++){
		getchar();
		char tp;
		scanf("%c",&tp);
		if (tp=='O'){
			int x;
			scanf("%d",&x);
			f[x]=true;
			for (set<int>::iterator it=bigf[x].begin();it!=bigf[x].end();it++){
				cnt[(*it)]++;
			}
		}
		else if (tp=='F'){
			int x;
			scanf("%d",&x);
			f[x]=false;
			for (set<int>::iterator it=bigf[x].begin();it!=bigf[x].end();it++){
				cnt[(*it)]--;
			}
		}
		else if (tp=='A'){
			int u,v;
			scanf("%d %d",&u,&v);
			deg[u]++;
			deg[v]++;
			if (deg[u]>Sqr){
				if (f[v]) cnt[u]++;
				bigf[v].insert(u);
			}
			else{
				smallf[v].insert(u);
			}
			if (deg[v]>Sqr){
				if (f[u]) cnt[v]++;
				bigf[u].insert(v);
			}
			else{
				smallf[u].insert(v);
			}
			if (deg[u]==Sqr+1){
				Update2(u);
			}
			if (deg[v]==Sqr+1){
				Update2(v);
			}
		}
		else if (tp=='D'){
			int u,v;
			scanf("%d %d",&u,&v);
			if (deg[u]>Sqr){
				if (f[v]) cnt[u]--;
				bigf[v].erase(u);
			}
			else{
				smallf[v].erase(u);
			}
			if (deg[v]>Sqr){
				if (f[u]) cnt[v]--;
				bigf[u].erase(v);
			}
			else{
				smallf[u].erase(v);
			}
			deg[u]--;
			deg[v]--;
			if (deg[u]==Sqr){
				Update3(u);
			}
			if (deg[v]==Sqr){
				Update3(v);
			}
		}
		else{
			int x;
			scanf("%d",&x);
			if (deg[x]>Sqr){
				printf("%d\n",cnt[x]);
			}
			else{
				Update(x);
				printf("%d\n",cnt[x]);
			}
		}
	}
}