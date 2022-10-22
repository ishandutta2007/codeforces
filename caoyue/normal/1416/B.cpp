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
const int N=1e6+7;
const int INF=1e9+7;
int T,n,cnt=0,vl;
int a[N];
struct wt{int x,y,z;}w[N];
void ins(int x,int y,int c){w[++cnt]=(wt){x,y,c}; a[x]-=x*c; a[y]+=x*c;}
struct pir{
	int x,v;
	friend bool operator < (pir a,pir b){return a.v>b.v;}
};
priority_queue<pir>Q;
bool solve(){
	REP(i,2,n)Q.push((pir){i,(i-a[i]%i)%i});
	while(!Q.empty()){
		pir o=Q.top();
		Q.pop();
		if(a[1]<o.v)break;
		if(o.v)ins(1,o.x,o.v);
		ins(o.x,1,a[o.x]/o.x);
	}
	REP(i,2,n){
		if(a[i]!=0&&a[i]!=vl)return 0;
		if(!a[i])ins(1,i,vl);
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		int s=0;
		rep(i,n)s+=a[i];
		cnt=0;
		if(s%n!=0){
			puts("-1");
			continue;
		}
		vl=s/n;
		bool fl=1;
		REP(i,2,n)if(a[i]!=a[i-1]){
			fl=0;
			break;
		}
		if(fl){
			puts("0");
			continue;
		}
		int mx=0;
		REP(i,2,n)if(a[i]>=i)mx=i;
		if(mx)ins(mx,1,a[mx]/mx);
		if(solve()){
			printf("%d\n",cnt);
			rep(i,cnt)printf("%d %d %d\n",w[i].x,w[i].y,w[i].z);
		}
		else puts("-1");
	}
	return 0;
}