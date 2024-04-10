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
const int N=2e5+7;
const int INF=1e9+7;
int T;
int a[N],c[N],vis[N],b[N],v[N];
vector<int>d[N];
struct pir{
	int x,v;
	friend bool operator < (pir a,pir b){return a.v>b.v;}
};
priority_queue<pir>Q;
struct pir2{
	int x,v;
	friend bool operator < (pir2 a,pir2 b){return a.v<b.v;}
};
priority_queue<pir2>Q2;

int main(){
	scanf("%d",&T);
	while(T--){
		int n,x,y; scanf("%d%d%d",&n,&x,&y);
		rep(i,n)scanf("%d",&a[i]);
		if(x==n){
			puts("YES");
			rep(i,n)printf("%d ",a[i]);
			puts("");
			continue;
		}
		rep(i,n+1)c[i]=v[i]=b[i]=0;
		while(!Q.empty())Q.pop();
		while(!Q2.empty())Q2.pop();
		rep(i,n)c[a[i]]++;
		int hh=0;
		rep(i,n+1)if(!c[i]){hh=i; break;}
		if(x==y){
			puts("YES");
			rep(i,x)printf("%d ",a[i]);
			rep(i,n-x)printf("%d ",hh);
			puts("");
			continue;
		}
		rep(i,n+1)d[i].clear();
		rep(i,n)d[a[i]].push_back(i);
		rep(i,n+1)if(c[i])Q.push((pir){i,1});
		rep(i,n-x){
			pir q=Q.top();
			Q.pop();
			v[q.x]=q.v;
			if(c[q.x]!=q.v)Q.push((pir){q.x,q.v+1});
		}
		int nw=n-x,gg=0;
		rep(i,n+1)if(v[i])Q2.push((pir2){i,v[i]});
		rep(i,n-y){
			if(i==n-y&&nw%2==0){
				gg=1;
				break;
			}
			pir2 q=Q2.top();
			Q2.pop();
			b[d[q.x][q.v-1]]=hh;
			if(q.v>1)Q2.push((pir2){q.x,q.v-1});
			nw--;
		}
		pir2 h=Q2.top();
		if(h.v+h.v>nw){
			puts("NO");
			continue;
		}
		for(;nw>3;nw-=2){
			pir2 h1=Q2.top();
			Q2.pop();
			pir2 h2=Q2.top();
			Q2.pop();
			b[d[h1.x][h1.v-1]]=a[d[h2.x][h2.v-1]];
			b[d[h2.x][h2.v-1]]=a[d[h1.x][h1.v-1]];
			if(h1.v!=1)Q2.push((pir2){h1.x,h1.v-1});
			if(h2.v!=1)Q2.push((pir2){h2.x,h2.v-1});
		}
		if(nw==2){
			pir2 h1=Q2.top();
			Q2.pop();
			pir2 h2=Q2.top();
			Q2.pop();
			b[d[h1.x][0]]=h2.x;
			b[d[h2.x][0]]=h1.x;
		}
		else{
			pir2 h1=Q2.top(); Q2.pop();
			pir2 h2=Q2.top(); Q2.pop();
			pir2 h3=Q2.top(); Q2.pop();
			b[d[h1.x][0]]=h2.x;
			b[d[h2.x][0]]=h3.x;
			b[d[h3.x][0]]=h1.x;
		}
		if(gg){
			rep(i,n)if(b[i]&&b[i]!=hh){
				b[i]=hh;
				break;
			}
		}
		rep(i,n)if(!b[i])b[i]=a[i];
		puts("YES");
		rep(i,n) printf("%d ",b[i]);
		puts("");
	}
	return 0;
}