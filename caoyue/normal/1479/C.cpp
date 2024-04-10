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
const int N=57;
const int INF=1e9+7;
int L,R,cnt=0;
struct Edge{int x,y,c;}E[N*N];
void build(){
	REP(i,7,26){
		int q=1<<(26-i);
		REP(j,i+1,27)E[++cnt]=(Edge){i,j,q};
	}
}
void work(int x){
	if(R<=5){
		if(R==1){
			E[++cnt]=(Edge){x,27,1};
			return;
		}
		if(R==2){
			E[++cnt]=(Edge){x,26,1};
			E[++cnt]=(Edge){x,27,1};
			return;
		}
		E[++cnt]=(Edge){x,27,1};
		E[++cnt]=(Edge){x,26,1};
		E[++cnt]=(Edge){x,x+1,1};
		E[++cnt]=(Edge){x+1,x+2,1};
		E[++cnt]=(Edge){x+2,x+3,1};
		if(R>=3)E[++cnt]=(Edge){x+1,26,1};
		if(R>=4)E[++cnt]=(Edge){x+2,26,1};
		if(R>=5)E[++cnt]=(Edge){x+3,26,1};
		return;
	}
	R--;
	E[++cnt]=(Edge){x,27,1};
	int nw=-1,s=1;
	while(R){
		nw++;
		if(R<(1<<nw))break;
		E[++cnt]=(Edge){x,26-nw,1};
		s+=(1<<nw);
		R-=(1<<nw);
	}
	if(!R)return;
	E[++cnt]=(Edge){x,3,1};
	rep0(q,20){
		if((R>>q)&1){
			E[++cnt]=(Edge){3,26-q,s-(1<<q)};
			s+=(1<<q);
		}
	}
}
int main(){
	scanf("%d%d",&L,&R);
	build();
	if(L!=1){
		E[++cnt]=(Edge){1,2,L-1};
		R=R-L+1;
		work(2);
	}
	else work(1);
	puts("YES");
	printf("27 %d\n",cnt);
	rep(i,cnt)printf("%d %d %d\n",E[i].x,E[i].y,E[i].c);
	return 0;
}