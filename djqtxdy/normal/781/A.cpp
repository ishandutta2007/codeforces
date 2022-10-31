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
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;
//orz mqy
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
const int Maxn=200005;
vector<int> G[Maxn];
bool vis[Maxn];
int dep[Maxn];
int col[Maxn];
bool use[Maxn];
int cc;
int p[Maxn];
void dfs(int x,int depth,int pr){
	vis[x]=true;
	dep[x]=depth;
	p[x]=pr;
	for (int i=0;i<G[x].size();i++){
		if (!vis[G[x][i]]) dfs(G[x][i],depth+1,x);
	}
}
void go(int x){
	vis[x]=true;
	int y,z;
	if (x==1) col[x]=1,use[1]=true;
	y=col[x];
	z=p[x];
	if (z!=-1) z=col[z];
//	cout<<x<<' '<<y<<z<<endl;
	int d=0;
	for (int i=0;i<G[x].size();i++){
		if (!vis[G[x][i]]){
			d++;
			if (d!=y && d!=z){
				col[G[x][i]]=d;
			}
			else{
				d++;
				if (d!=y && d!=z){
					col[G[x][i]]=d;
				}
				else{
					col[G[x][i]]=++d;
				}
			}
			use[d]=true;
			cc=max(cc,d);
			go(G[x][i]);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0,-1);
	memset(vis,false,sizeof(vis));
	go(1);
	printf("%d\n",cc);
	for (int i=1;i<=n;i++){
		printf("%d ",col[i]);
	}
	printf("\n");
	return 0;
}