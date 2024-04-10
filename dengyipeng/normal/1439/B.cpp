#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#define maxn 100005
#define maxh 10000007
using namespace std;

int T,n,m,i,j,k,du[maxn],bz[maxn],K,a[maxn][2];
struct arr{int x,i;arr(int _x=0,int _i=0){x=_x,i=_i;}};
int operator<(arr a,arr b){return a.x>b.x;}
priority_queue<arr> q;
set<int> e[maxn];
set<int>::iterator it;
int hs[maxh],hs0[maxh][2];

void insert(int x,int y){
	if (x>y) swap(x,y);
	int k=(1ll*x*23333+1ll*y*19260817)%maxh;
	while (hs[k]&&(hs0[k][0]!=x||hs0[k][1]!=y))
		k=(k+1)%maxh;
	hs[k]=1,hs0[k][0]=x,hs0[k][1]=y;
	if (k==3510565)
		printf("");
	e[x].insert(y),e[y].insert(x);
	du[x]++,du[y]++;
}
int check(int x,int y){
	if (x>y) swap(x,y);
	int k=(1ll*x*23333+1ll*y*19260817)%maxh;
	while (hs[k]&&(hs0[k][0]!=x||hs0[k][1]!=y))
		k=(k+1)%maxh;
	return hs[k];
}
void del(int x,int y){
	if (x>y) swap(x,y);
	if (x==7&&y==9)
		printf("");
	int k=(1ll*x*23333+1ll*y*19260817)%maxh;
	while (hs[k]) 
		hs[k]=hs0[k][0]=hs0[k][1]=0,k=(k+1)%maxh;
}

int d[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&n,&m,&K);
		memset(du,0,sizeof(int)*(n+1));
		memset(bz,0,sizeof(int)*(n+1));
		for(i=1;i<=n;i++) e[i].clear();
		while (!q.empty()) q.pop();
		for(i=1;i<=m;i++) {
			scanf("%d%d",&j,&k),insert(j,k);a[i][0]=j,a[i][1]=k;	
		}
		for(i=1;i<=n;i++) q.push(arr(du[i],i));
		int tp=0;
		while (!q.empty()){
			arr tmp=q.top(); q.pop();
			if (tmp.x!=du[tmp.i]||bz[tmp.i]) continue;
			if (tmp.x>=K){
				tp=1;
				int cnt=0;
				for(i=1;i<=n;i++) if (!bz[i]) cnt++;
				printf("1 %d\n",cnt);
				for(i=1;i<=n;i++) if (!bz[i]) printf("%d ",i);
				printf("\n");
				tp=1;break;
			} else 
			if (tmp.x<K-1) {
				int x=tmp.i;
				for(it=e[x].begin();it!=e[x].end();it++){
					du[*it]--,e[*it].erase(x);
					q.push(arr(du[*it],*it));
				}
				bz[x]=1;
			} else 
			if (tmp.x==K-1){
				int x=tmp.i; 
				d[0]=0;
				for(it=e[x].begin();it!=e[x].end();it++)
					d[++d[0]]=*it;
				int tp0=1;
				if (1ll*K*(K-1)/2<=m){
					for(i=1;i<=d[0];i++){
						for(j=i+1;j<=d[0];j++){
							if (!check(d[i],d[j])){
								tp0=0;
								break;
							}
						}
						if (!tp0) break;
					}
				} else tp0=0;
				if (tp0) {
					printf("2\n");
					printf("%d ",x);
					for(i=1;i<=d[0];i++) printf("%d ",d[i]);
					printf("\n");
					tp=1;break;
				} else {
					for(it=e[x].begin();it!=e[x].end();it++){
						du[*it]--,e[*it].erase(x);
						q.push(arr(du[*it],*it));
					}
					bz[x]=1;
				}
			}
		}
		if (!tp) printf("-1\n");
		for(i=1;i<=m;i++) 
			del(a[i][0],a[i][1]);
	}
}