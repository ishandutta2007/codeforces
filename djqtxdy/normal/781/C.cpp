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
int p[Maxn];
vector<int> G[Maxn];
bool vis[Maxn];
void _init(){
	for (int i=0;i<Maxn;i++){
		p[i]=i;
	}
}
int findset(int x){
	return p[x]=(p[x]==x)?x:findset(p[x]);
}
void Union(int x,int y){
	x=findset(x);
	y=findset(y);
	p[y]=x;
}
int ste;
vector<int> ans;
vector<int> aa[Maxn];
void dfs(int x){
	ans.push_back(x);
	vis[x]=true;
	bool flag=false;
	for (int i=0;i<G[x].size();i++){
		if (!vis[G[x][i]]) dfs(G[x][i]),ans.push_back(x);
	}
}
int main(){
	_init();
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for (int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		if (findset(x)!=findset(y)){
			Union(x,y); 
			G[x].push_back(y);
			G[y].push_back(x); 
		}
	}
	dfs(1);
	ste=(n*2-1)/k+1;
	int tot=0;
	for (int i=0;i<ans.size();i++){
		aa[i/ste].push_back(ans[i]);
	}
	for (int i=0;i<k;i++){
		if (aa[i].size())printf("%d ",aa[i].size());
		else printf("1 1");
		for (int j=0;j<aa[i].size();j++){
			printf("%d ",aa[i][j]);
		} 
		printf("\n");
	}
	return 0;
}