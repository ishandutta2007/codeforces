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
const int N=5e5+7;
const int INF=1e9+7;
int a,b,c1=0,c2=0;
int t1[N],t2[N];
bool d[N];

int main(){
	scanf("%d%d",&a,&b);
	int q=a+b,nw=0,cnt=0;
	while(nw+cnt+1<=q){
		cnt++;
		nw+=cnt;
	}
	for(int i=cnt;i;i--){
		if(a>=i){
			a-=i;
			d[i]=1;
		}
		else{
			d[a]=1;
			break;
		}
	}
	rep(i,cnt)if(d[i])t1[++c1]=i;else t2[++c2]=i;
	printf("%d\n",c1);
	rep(i,c1)printf("%d ",t1[i]);
	printf("\n");
	printf("%d\n",c2);
	rep(i,c2)printf("%d ",t2[i]);
	printf("\n");
	return 0;
}