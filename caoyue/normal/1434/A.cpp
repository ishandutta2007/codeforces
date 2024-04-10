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
int n;
int a[N],b[6],nw[N];
struct pir{
	int x,v;
	friend bool operator < (pir a,pir b){return (a.v!=b.v)?a.v<b.v:a.x<b.x;}
}; 
set<pir>S;
int query(){
	set<pir>::iterator h1=S.end(),h2=S.begin();
	h1--;
	return ((*h1).v-(*h2).v);
}
int main(){
	rep0(i,6)scanf("%d",&b[i]);
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	sort(b,b+6);
	rep(i,n)nw[i]=5;
	rep(i,n)S.insert((pir){i,a[i]-b[5]});
	int ans=query();
	while(1){
		pir q=*S.begin();
		if(!nw[q.x])break;
		nw[q.x]--;
		S.erase(q);
		S.insert((pir){q.x,a[q.x]-b[nw[q.x]]});
		ans=min(ans,query());
	}
	printf("%d\n",ans);
	return 0;
}