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
const int Maxn=100005;
vector<pair<int,int> > G[Maxn];
bool zero[Maxn];
int dist[Maxn],zerodist[Maxn],zeronxt[Maxn];
int nxt[Maxn];
bool vis[Maxn];
int n,m;
void bfs1(){
	queue<int> Q;
	Q.push(n-1);
	for (int i=0;i<Maxn;i++) zerodist[i]=1e9;
	memset(zero,false,sizeof(zero));
	for (int i=0;i<Maxn;i++) zeronxt[i]=-1;
	zerodist[n-1]=0;
	zero[n-1]=true;
	while (!Q.empty()){
		int x=Q.front();
		Q.pop();
		for (int i=0;i<G[x].size();i++){
			int v=G[x][i].first;
			if (G[x][i].second==0 && zerodist[v]==1e9){
				zerodist[v]=zerodist[x]+1;
				zero[v]=true;
				zeronxt[v]=x;
				Q.push(v);
			}
		} 
	}
}
void bfs2(){
	queue<int> Q;
	Q.push(0);
	for (int i=0;i<Maxn;i++) dist[i]=1e9;
	dist[0]=0;
	while (!Q.empty()){
		int x=Q.front();
		Q.pop();
		for (int i=0;i<G[x].size();i++){
			int v=G[x][i].first;
			if (dist[v]==1e9){
				dist[v]=dist[x]+1;
				Q.push(v);
			}
		}
	}
}
void P(vector<int> &res){
	for (int i=0;i<res.size();i++){
		printf("%d",res[i]);
	}
	printf("\n");
	vector<int> r;
	int Now=0;
	while (!zero[Now]){
		r.push_back(Now);
		Now=nxt[Now];
	}
	while (Now!=-1){
		r.push_back(Now);
		Now=zeronxt[Now];
	}
	printf("%d\n",r.size());
	for (int i=0;i<r.size();i++){
		printf("%d ",r[i]);
	}
	printf("\n");
}
bool cmp(int x,int y){
	return zerodist[x]<zerodist[y];
}
int main(){

	scanf("%d %d",&n,&m);
	for (int i=0;i<m;i++){
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);
		G[u].pb(mp(v,c));
		G[v].pb(mp(u,c));
	}
	bfs1();
	if (zero[0]){
		printf("0\n");
		printf("%d\n",zerodist[0]+1);
		int x=0;
		for (;x!=-1;x=zeronxt[x]){
			printf("%d ",x);
		}
		printf("\n");
		return 0;
	}
	bfs2();
	vector<int> now,New,ans;
	int MM=1e9;
	for (int i=0;i<n;i++){
		if (zero[i])MM=min(MM,dist[i]);
	}
	for (int i=0;i<n;i++){
		if (zero[i] && dist[i]==MM) now.push_back(i),vis[i]=true;
	}
	sort(now.begin(),now.end(),cmp);
	//cout<<now[0]<<" "<<now[1]<<endl;
	int Mn=15;
	for (int i=0;i<now.size();i++){
		int v=now[i];
		for (int j=0;j<G[v].size();j++){
			int u=G[v][j].first;
			if (dist[u]==dist[v]-1 && G[v][j].second!=0){
				Mn=min(Mn,G[v][j].second);
			}
		}
	}
	ans.push_back(Mn);
	for (int i=0;i<now.size();i++){
		int v=now[i];
		for (int j=0;j<G[v].size();j++){
			int u=G[v][j].first;
			if (dist[u]==dist[v]-1 && G[v][j].second==Mn){
				if (vis[u]) continue;
				vis[u]=true;
				nxt[u]=v;
				if (u==0){
					P(ans);
					return 0;
				}
				
				New.push_back(u); 
			}
		}
	}
	now=New;
	New.clear();
	while (1){
	//	cout<<now[0]<<" "<<now[1]<<endl;
		Mn=15;
		for (int i=0;i<now.size();i++){
			int v=now[i];
			for (int j=0;j<G[v].size();j++){
				int u=G[v][j].first;
				if (dist[u]==dist[v]-1){
					Mn=min(Mn,G[v][j].second);
				}
			}
		}
		ans.push_back(Mn);
		for (int i=0;i<now.size();i++){
			int v=now[i];
			for (int j=0;j<G[v].size();j++){
				int u=G[v][j].first;
				if (dist[u]==dist[v]-1 && G[v][j].second==Mn){
					if (vis[u]) continue;
				vis[u]=true;
					nxt[u]=v;
					if (u==0){
						P(ans);
						return 0;
					}
					
					New.push_back(u); 
				}
			}
		}
		now=New;
		New.clear();
	//	cout<<now[0]<<endl;
		//cout<<dist[now[0]]<<endl;
	}
}
/*
6 6
5 1 0
5 2 1
1 3 1
2 4 2
3 4 2
4 0 0
*/