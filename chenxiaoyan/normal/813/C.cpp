/*









 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200000;
int n,m;
vector<int> nei[N+1];
int fa[N+1],dep[N+1];
void dfs1(int x=1){
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa[x])continue;
		fa[y]=x;
		dep[y]=dep[x]+1;
		dfs1(y);
	}
}
int dfs2(int x){
	int res=dep[x];
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa[x])continue;
		res=max(res,dfs2(y));
	}
	return res;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		nei[x].pb(y);nei[y].pb(x);
	}
	dfs1();
	int up=dep[m]&1?dep[m]/2:dep[m]/2-1;
	while(up--)m=fa[m];
	cout<<dfs2(m)*2;
	return 0;
}
/*1
4 3
1 2
2 3
2 4
*/
/*2
5 2
1 2
2 3
3 4
2 5
*/