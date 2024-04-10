#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<vector>
#include<bitset>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e5+7;
const int M=1e6+7;
const int INF=1e9+7;
int n,cnt=0,tot=0;
set<int>S[N];
int w[M],p[N],L[N];
void dfs1(int x){
	L[x]=0;
	for(set<int>::iterator s=S[x].begin();s!=S[x].end();s++){
		dfs1(*s);
		L[x]=max(L[x],L[*s]+1);
	}
}
void dfs2(int x){
	p[++tot]=x;
	if(!S[x].size())return;
	int mx=-1,id;
	for(set<int>::iterator s=S[x].begin();s!=S[x].end();s++){
		if(L[*s]>mx){
			mx=L[*s];
			id=*s;
		}
	}
	int nw=id;
	for(set<int>::iterator s=S[x].begin();s!=S[x].end();s++){
		if(*s==id)continue;
		S[*s].insert(nw);
		L[*s]=max(L[*s],L[nw]+1);
		w[++cnt]=nw;
		nw=*s;
	}
	dfs2(nw);
}
int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int x; scanf("%d",&x);
		S[x].insert(i);
	}
	dfs1(0);
	dfs2(0);
	rep(i,n)printf("%d ",p[i]);
	puts("");
	printf("%d\n",cnt);
	for(int i=cnt;i;i--)printf("%d ",w[i]);
	puts("");
	return 0;
}