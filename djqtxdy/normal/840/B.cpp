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
const int Maxn=300005;
vector<pair<int,int> > G[Maxn];
bool vis[Maxn];
vector<pair<int,int> > e;
int p[Maxn];
bool dp[Maxn][2];
vector<int> choose[Maxn][2];
int col[Maxn];
vector<int> ans;
int findset(int x){
	return p[x]=(p[x]==x)?x:findset(p[x]);
}
void Union(int x,int y){
	x=findset(x);
	y=findset(y);
	p[x]=y;
}
void _init(){
	for (int i=0;i<Maxn;i++) p[i]=i;
}
void dfs(int x){
	vis[x]=true;
	vector<int>mustadd,canadd;
	bool flag=false;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i].first;
		if (!vis[v]){
			flag=true;
			dfs(v);
			if (dp[v][1] && !dp[v][0]) mustadd.push_back(G[x][i].second);
			else if (dp[v][1] && dp[v][0]) canadd.push_back(G[x][i].second);
		}
	}
	if (!flag){
		if (col[x]==-1){
			dp[x][0]=dp[x][1]=true;
		}
		else{
			dp[x][col[x]]=true;
		}
		return;
	}
	int nc=col[x];
	if (nc==-1){
		dp[x][0]=dp[x][1]=true;
		choose[x][0]=mustadd;
		choose[x][1]=mustadd;
		return;
	}
	int ns=mustadd.size();
	ns&=1;
	nc=nc^ns;
	if (canadd.empty()){
		dp[x][nc]=true;
		choose[x][nc]=mustadd;
	}
	else{
		dp[x][nc]=dp[x][!nc]=true;
		choose[x][nc]=mustadd;
		choose[x][!nc]=mustadd;
		choose[x][!nc].push_back(canadd[0]);
	}
}
void go(int x){
	//cerr<<x<<endl;
	vis[x]=true;
	if (1){
		for (int i=0;i<choose[x][0].size();i++){
			ans.pb(choose[x][0][i]);
			//out<<choose[x][0][i]<<
			pii xxx=e[choose[x][0][i]-1];
			int v=(x==xxx.first)?xxx.second:xxx.first;
			if (col[v]!=-1) col[v]^=1,swap(choose[v][0],choose[v][1]);
		}
	}
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i].first;
		if (!vis[v]){
			go(v);
		}
	}
}
int main(){
	_init();
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&col[i]);
	}
	for (int i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		e.pb(mp(u,v));
	}
	for (int i=0;i<e.size();i++){
		int u=e[i].first,v=e[i].second;
		if (findset(u)!=findset(v)){
			G[u].push_back(mp(v,i+1));
			G[v].pb(mp(u,i+1));
			Union(u,v);
		}
	}
	memset(vis,false,sizeof(vis));
	dfs(1);
	if (!dp[1][0]){
		printf("-1\n");
		return 0;
	}
	//cout<<choose[1][0].size()<<' '<<choose[1][1].size()<<endl;
	memset(vis,false,sizeof(vis));
	//cerr<<123<<endl;
	go(1);
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}