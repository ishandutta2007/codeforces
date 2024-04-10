#include<bits/stdc++.h>
using namespace std;
#define dec(x) _##x[2*N+1],*x=_##x+N
#define N 100000
#define pb push_back
vector<int> dec(nei),scc[2*N+1],cnei[2*N+1];
int n,dec(cid),dec(dfn),dec(low),nowdfn,cnt;
bool dec(ins);
bitset<2*N+1> vis;
stack<int> stk;
char cs[N+10];string ae,cae;
void dfs(int x){
	low[x]=dfn[x]=++nowdfn;
	stk.push(x);ins[x]=true;
	for(int i=0;i<nei[x].size();i++){
		int to=nei[x][i];
		if(!dfn[to])dfs(to),low[x]=min(low[x],low[to]);
		else if(ins[to])low[x]=min(low[x],dfn[to]);
	}
	if(low[x]==dfn[x]){
		cnt++;
		do{
			x=stk.top();stk.pop();ins[x]=false;
			cid[x]=cnt;scc[cnt].pb(x);
		}while(low[x]!=dfn[x]);
	}
}
inline bool cmp(int x,int y){return abs(x)<abs(y);}
bool dfs0(int x){
	for(int i=0;i<cnei[x].size();i++){
		int to=cnei[x][i];
		if(vis[to])continue;vis.set(to);
		if(cae[to]=='A'||dfs0(to))return true;
	}
	return false;
}
void mian(){
	int m,i,j;scanf("%d%d%s",&n,&m,cs);ae=cs;ae=" "+ae;
	while(m--){int x,y;scanf("%d%d",&x,&y);nei[-x].pb(y);nei[-y].pb(x);}
//	for(i=-n;i<=n;i++,i+=!i)
//		{cout<<"nei["<<i<<"]=";for(j=0;j<nei[i].size();j++)cout<<nei[i][j]<<" ";puts("");}
	for(i=-n;i<=n;i++,i+=!i)if(!dfn[i])dfs(i);
	for(i=1;i<=n;i++)if(cid[i]==cid[-i]){puts("FALSE");return;}
	for(i=1;i<=cnt;i++)sort(scc[i].begin(),scc[i].end(),cmp);
//	for(i=1;i<=cnt;i++)
//		{cout<<"SCC#"<<i<<":";for(j=0;j<scc[i].size();j++)cout<<scc[i][j]<<" ";puts("");}
	for(i=1;i<=cnt;i++)for(j=1;j<scc[i].size();j++)
		if(ae[abs(scc[i][j])]=='A'){puts("FALSE");return;}
	cae=" ";
	for(i=1;i<=cnt;i++){
		cae+=ae[abs(scc[i][0])];
		for(j=0;j<scc[i].size();j++)for(int k=0;k<nei[scc[i][j]].size();k++){
			int to=cid[nei[scc[i][j]][k]];
			if(to!=i)cnei[i].pb(to);
		}
	}
//	for(i=1;i<=cnt;i++)
//		{cout<<"SCC#"<<i<<":";for(j=0;j<cnei[i].size();j++)cout<<cnei[i][j]<<" ";puts("");}
//	cout<<cae<<"\n";
	for(i=1;i<=cnt;i++)if(cae[i]=='A')if(dfs0(i)){puts("FALSE");return;}
	puts("TRUE");
}
int main(){
	int ASK,i;scanf("%d",&ASK);
	while(ASK--){
		for(i=-n;i<=n;i++,i+=!i)nei[i].clear(),cid[i]=dfn[i]=low[i]=ins[i]=0;
		for(i=1;i<=cnt;i++)cnei[i].clear(),scc[i].clear(),vis.reset(i);
		nowdfn=cnt=0;
		while(stk.size())stk.pop();
		mian();
	}
	return 0;
}
/*1
3
2 2
AE
1 -2
-1 2
2 2
EA
1 -2
-1 2
3 2
AEA
1 -2
-1 -3
*/
/*2
10
3 3
AEA
1 -2
2 3
-2 3
5 3
AEAAE
2 3
-4 -2
1 -4
8 6
AAAEEAEE
-8 -1
8 -7
-8 1
1 1
-6 -3
4 2
7 2
EEAAEAA
6 2
7 5
5 3
AEEEE
1 3
2 -3
-3 -1
9 4
EEAAAEAAA
4 -2
-3 -1
-6 -2
7 -8
7 4
AEEEEEA
-7 -5
4 7
1 7
2 -6
6 5
EAAAEE
-5 2
1 -3
6 2
5 2
-6 5
5 4
AEAAA
-2 5
-3 -1
5 3
1 -5
7 9
EEEEAAA
-1 4
7 -5
-4 -3
1 7
3 4
-3 -1
-7 -2
2 -7
-5 2
*/