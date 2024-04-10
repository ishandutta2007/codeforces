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
unsigned long long u[N*5];
map<int,int>mp;
struct hh{
	int a[5];
	int w;
}h[N];
int n,m,cc=0;
bool cmp(hh a,hh b){return a.w<b.w;}
int p[N];
int check(unsigned long long S){
	S=S&(-S);
	int t=log2(S)+0.5;
	return t;
}
int main(){
	scanf("%d%d",&n,&m);
	rep0(i,n){
		rep0(j,m)scanf("%d",&h[i].a[j]);
		scanf("%d",&h[i].w);
	}
	sort(h,h+n,cmp);
	int ans=INF+INF,ps=0;
	for(int i=n-1;~i;i--)p[++ps]=i;
	while(n%64!=0){
		rep0(j,m)h[n].a[j]=j+1;
		h[n].w=INF;
		n++;
	}
	rep0(i,n)rep0(j,m)mp[h[i].a[j]]=1;
	for(map<int,int>::iterator o=mp.begin();o!=mp.end();o++)mp[o->first]=++cc;
	rep0(i,n){
		rep0(j,m)h[i].a[j]=mp[h[i].a[j]];
		REP(j,m,4)h[i].a[j]=0;
	}
	unsigned long long S0=0;
	S0--;
	rep(i,cc)u[i]=S0;
	u[0]=S0;
	rep0(i,n/64){
		rep0(j,64){
			unsigned long long S=S0;
			rep0(k,m){
				S&=u[h[i*64+j].a[k]];
				u[h[i*64+j].a[k]]-=(1ull<<j);
			}
			if(p[ps]==i*64+j){
				ps--;
				if(!S)continue;
				int t=check(S);
				if(t<j)ans=min(ans,h[i*64+j].w+h[i*64+t].w);
			}
		}
		int nps=0;
		rep(j,ps){
			if(u[h[p[j]].a[0]]&u[h[p[j]].a[1]]&u[h[p[j]].a[2]]&u[h[p[j]].a[3]]&u[h[p[j]].a[4]]){
				unsigned long long S=u[h[p[j]].a[0]]&u[h[p[j]].a[1]]&u[h[p[j]].a[2]]&u[h[p[j]].a[3]]&u[h[p[j]].a[4]];
				int t=check(S);
				ans=min(ans,h[p[j]].w+h[i*64+t].w);
			}
			else p[++nps]=p[j];
		}
		ps=nps;
		rep0(j,64)rep0(k,m)u[h[i*64+j].a[k]]+=(1ull<<j);
	}
	if(ans==INF+INF)puts("-1");
	else printf("%d\n",ans);
	return 0;
}