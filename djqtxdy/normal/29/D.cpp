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
const int Maxn=305;
vector<int> G[Maxn],son[Maxn];
int p[Maxn],dep[Maxn];
bool vis[Maxn];
set<int> contain[Maxn];
int list[Maxn];
int cnt=0;
void dfs(int x,int depth){
	dep[x]=depth;
	vis[x]=true;
	bool flag=true;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!vis[v]){
			dfs(v,depth+1);
			for (set<int>::iterator it=contain[v].begin();it!=contain[v].end();it++){
				contain[x].insert(*it);
			}
			p[v]=x;
			flag=false;
			son[x].push_back(v);
		}
	}
	if (flag) contain[x].insert(x),cnt++;
}
int lca(int u,int v){
	if (dep[u]>dep[v]) swap(u,v);
	int diff=dep[v]-dep[u];
	for (int i=0;i<diff;i++) v=p[v];
	while (u!=v) u=p[u],v=p[v];
	return u;
}
vector<int> ans;
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	for (int i=0;i<cnt;i++) scanf("%d",&list[i]);
	int now=1;
	ans.push_back(now);
	for (int i=0;i<cnt;i++){
		while (now!=list[i]){
			for (int j=0;j<son[now].size();j++){
				int v=son[now][j];
				if (contain[v].find(list[i])!=contain[v].end()){
					now=v;
					ans.push_back(now);
					break;
				}
			}
		}
		int vv;
		if (i!=cnt-1)vv=lca(list[i],list[i+1]);
		else vv=1;
		while (now!=vv){
			now=p[now];
			ans.push_back(now);
		}
	}
	if (ans.size()!=2*n-1){
		printf("-1\n");
	}
	else{
		for (int i=0;i<ans.size();i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
		return 0;
	}
	return 0;

}