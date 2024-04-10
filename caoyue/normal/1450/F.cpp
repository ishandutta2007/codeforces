#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e5+7;
const int INF=1e9+7;
int T,n,mx;
int a[N],dg[N];
map<int,int>S[N];
void add(int x,int y){
	if(S[x].count(y))S[x][y]++;
	else S[x][y]=1;
	if(S[y].count(x))S[y][x]++;
	else S[y][x]=1;
}
struct pir{
	int x,v;
	friend bool operator < (pir u,pir v){return (u.v!=v.v)?u.v<v.v:u.x<v.x;}
};
priority_queue<pir>Q,Qd;
void clear(){
	while(!Qd.empty()){
		if(Q.top().x==Qd.top().x&&Q.top().v==Qd.top().v){
			Qd.pop();
			Q.pop();
		}
		else break;
	}
}
void Er(int x,int y){
	dg[x]--;
	if(S[x][y]==1){
		S[x].erase(y);
		if(S[x].begin()==S[x].end())mx=max(mx,dg[x]);
		else Q.push((pir){x,dg[x]});
	}
	else{
		S[x][y]--;
		Q.push((pir){x,dg[x]});
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		while(!Q.empty())Q.pop();
		while(!Qd.empty())Qd.pop(); 
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n){
			dg[i]=0;
			S[i].clear();
		}
		rep(i,n)dg[a[i]]+=2;
		rep(i,n-1)if(a[i]!=a[i+1])add(a[i],a[i+1]);
		int nw=2*n,ans=-1;
		mx=0;
		rep(i,n){
			if(S[i].begin()!=S[i].end())Q.push((pir){i,dg[i]});
			else mx=max(mx,dg[i]);
		}
		while(1){
			clear();
			if(Q.empty())break;
			pir h=Q.top();
			if(2*max(dg[h.x],mx)>nw+2)break;
			ans=nw/2-1;
			Q.pop();
			map<int,int>::iterator o=S[h.x].begin();
			int oo=o->first;
			Qd.push((pir){oo,dg[oo]});
			Er(h.x,oo);
			Er(oo,h.x);
			nw-=2;
		}
		if(Q.empty())if(2*mx<=nw+2)ans=nw/2-1;
		printf("%d\n",ans);
	}
	return 0;
}