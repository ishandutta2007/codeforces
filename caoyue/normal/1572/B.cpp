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
int T,n,cnt;
int b[N],op[N];
void work(int x){
	if(b[x+1]){
		op[++cnt]=x;
		b[x]=b[x+1]=0;
		while(!b[x]&&x<=n)x++;
		if(x<=n)work(x);
	}
	else if(b[x+2]){
		op[++cnt]=x+1;
		b[x]=b[x+2]=0;
		while(!b[x]&&x<=n)x++;
		if(x<=n)work(x);
	}
	else{
		op[++cnt]=x+1;
		op[++cnt]=x;
		b[x+2]=1;
		b[x]=0;
		while(!b[x]&&x<=n)x++;
		if(x<=n)work(x);
	}
}
void print(){
	puts("YES");
	printf("%d\n",cnt);
	rep(i,cnt)printf("%d ",op[i]-1);
	puts("");
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n)scanf("%d",&b[i]);
		int c1=cnt=0;
		rep(i,n)c1+=b[i];
		if(c1&1){
			puts("NO");
			continue;
		}
		int nw=1;
		while(nw<=n&&!b[nw])nw++;
		if(nw>n){
			print();
			continue;
		}
		if(nw!=1){
			work(nw);
			print();
			continue;
		}
		int nr=1;
		while(1){
			while(nr<n&&b[nr+1])nr++;
			if(nr==n){
				puts("NO");
				break;
			}
			if((nr-nw+1)%2==0){
				for(int j=nr;j>nw;j-=2)op[++cnt]=j;
				int x=nr+1;
				while(x<=n&&!b[x])x++;
				if(x<=n)work(x);
				print();
				break;
			}
			if(b[nr+2]==1){
				op[++cnt]=nr+1;
				for(int j=nr-1;j>nw;j-=2)op[++cnt]=j;
				int x=nr+3;
				while(x<=n&&!b[x])x++;
				if(x<=n)work(x);
				print();
				break;
			}
			op[++cnt]=nr+1;
			b[nr+1]=b[nr+2]=1;
		}
	}
	return 0;
}