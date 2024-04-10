#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e5+7;
const int INF=2e9+7;
int n,m,nw=-1;
int Ans[N];
struct pt{int x,y;}p[N];
struct wt{int x,y,id;}w[N];
bool cmp1(pt a,pt b){return a.x<b.x;}
bool cmp2(wt a,wt b){return a.x<b.x;}
set<int>S,cS;

int main(){
	scanf("%d%d",&n,&m);
	rep(i,n){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	sort(p+1,p+n+1,cmp1);
	rep(i,m){
		scanf("%d%d",&w[i].x,&w[i].y);
		w[i].id=i;
	}
	sort(w+1,w+m+1,cmp2);
	int nw1=1,nw2=1;
	rep0(i,INF){
		if(nw2>m)break;
		set<int>::iterator u=S.upper_bound(nw);
		int t1=(u==S.end())?INF:(*u),t2=(nw1<=n)?p[nw1].x:INF,t3=w[nw2].x;
		int q=min(min(t1,min(t2,t3))-i,t1-nw);
		if(q>5){
			nw+=q-1;
			i+=q-2;
			continue;
		}
		cS.clear();
		while(nw1<=n&&p[nw1].x==i){
			cS.insert(p[nw1].y);
			S.insert(p[nw1].y);
			nw1++;
		}
		set<int>::iterator o=cS.upper_bound(nw);
		if(o==cS.begin()){
			while(1){
				nw++;
				if(cS.count(nw))break;
				if(!S.count(nw))break;
			}
			cS.insert(nw);
		}
		while(nw2<=m&&w[nw2].x==i){
			if(cS.count(w[nw2].y))Ans[w[nw2].id]=0;
			else Ans[w[nw2].id]=1;
			nw2++;
		}
	}
	rep(i,m)if(Ans[i])puts("WIN");else puts("LOSE");
	return 0;
}