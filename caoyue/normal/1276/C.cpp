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
const int N=4e5+7;
const int INF=1e9+7;
int n;
int a[N],w[N],s[N],vx[N],vy[N];
vector<int>h[N];
struct pir{int x,v;}p[N];
bool cmp(pir a,pir b){return a.v<b.v;} 
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	rep(i,n){
		if(i>1&&a[i]==a[i-1])s[i]=s[i-1];
		else s[i]=i;
		w[s[i]]++;
	}
	int id,cnt=0,mx=0,nw=1,ss=0,r,c,gg;
	rep(i,n)if(w[i])p[++cnt]=(pir){i,w[i]};
	sort(p+1,p+cnt+1,cmp);
	rep(i,n){
		while(p[nw].v==i-1&&nw<=cnt){
			ss+=p[nw].v;
			nw++;
		}
		int u=ss+(cnt-nw+1)*i;
		if(u/i<i)continue;
		if(i*(u/i)>mx){
			mx=i*(u/i);
			id=i;
			r=i;
			c=u/i;
			gg=nw;
		}
	}
	int tot=0;
	rep0(i,r)h[i].clear();
	rep0(i,c){
		rep0(j,r){
			h[j].push_back(0);
			vx[++tot]=j;
			vy[tot]=(i+j)%c;
		}
	}
	int pp=0;
	for(int i=cnt;i;i--){
		int o=min(p[i].v,r);
		rep(j,o){
			pp++;
			if(pp>r*c)break;
			h[vx[pp]][vy[pp]]=a[p[i].x];
		}
		if(pp>r*c)break;
	}
	printf("%d\n",r*c);
	printf("%d %d\n",r,c);
	rep0(i,r){
		rep0(j,c)printf("%d ",h[i][j]);
		puts("");
	}
	return 0;
}