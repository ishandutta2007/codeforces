#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=3e5+7;
const int INF=1e9+7;
struct pir{int x,d;}s[N],t[N],p[N];
int g[N],el[N],er[N],ed[N];
int n,tp=0,m=0;
bool cmp(pir a,pir b){return a.x<b.x;}
void add(int x,int y,int c){
	if(x>y)swap(x,y); 
	x=s[x].d;
	y=s[y].d;
	el[++m]=x;
	er[m]=y;
	ed[m]=c;
}
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&s[i].x),s[i].d=i;
	rep(i,n)scanf("%d",&t[i].x),t[i].d=i;
	sort(s+1,s+n+1,cmp);
	sort(t+1,t+n+1,cmp);
	rep(i,n)g[i]=t[i].x-s[i].x;
	rep(i,n){
		if(!g[i])continue;
		if(g[i]<0){
			g[i]*=-1;
			while(tp&&p[tp].x<=g[i]){
				add(p[tp].d,i,p[tp].x);
				g[i]-=p[tp].x;
				tp--;
			}
			if(!g[i])continue;
			if(tp){
				add(p[tp].d,i,g[i]);
				p[tp].x-=g[i];
			}
			else {
				puts("NO");
				return 0;
			}
		}
		else p[++tp]=(pir){g[i],i};
	}
	if(tp){
		puts("NO");
		return 0;
	} 
	puts("YES");
	printf("%d\n",m);
	rep(i,m)printf("%d %d %d\n",el[i],er[i],ed[i]);
	return 0;
}