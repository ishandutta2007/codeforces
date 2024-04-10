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
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=2e5+7;
const int INF=1e9+7;
int s[N],p[N],q[N];
int n,d;

int main(){
	scanf("%d%d",&n,&d);
	rep(i,n)scanf("%d",&s[i]);
	rep(i,n)scanf("%d",&p[i]);
	int T=s[d]+p[1],cnt=0;
	p[n+1]=-INF;
	rep(i,n){
		if(i==d)continue;
		cnt++;
		int L=1,R=n+1;
		while(L<R-1){
			int mid=(L+R)>>1;
			if(p[mid]+s[i]<=T)R=mid;
			else L=mid;
		}
		if(p[L]+s[i]<=T)q[cnt]=L;
		else q[cnt]=R;
		q[cnt]=n-q[cnt]+1;
	}
	int k=0,ans=1;
	rep(i,n-1)if(q[i]<i-k){ans++; k++;}
	printf("%d\n",ans);
	return 0;
}
//4 4 5 5 5 1 3 2 1 1