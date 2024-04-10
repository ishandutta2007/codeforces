#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep0(i,n) REP(i,0,n-1)
#define rep(i,n) REP(i,1,n)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
const int N=2e5+7;
const int INF=1e9+7;
struct pir{int id,j;};
map<int,pir>q;
int k;
int l[N];
int main(){
	scanf("%d",&k);
	rep(i,k){
		int n,sum=0; scanf("%d",&n);
		rep(j,n)scanf("%d",&l[j]),sum+=l[j];
		rep(j,n){
			if(q.count(sum-l[j])){
				pir w=q[sum-l[j]];
				if(w.id==i)continue;
				printf("YES\n");
				printf("%d %d\n",w.id,w.j);
				printf("%d %d\n",i,j);
				return 0;
			}
			q[sum-l[j]]=(pir){i,j};
		}
	}
	printf("NO\n");
	return 0;
}