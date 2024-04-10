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
const int N=1e6+7;
const int INF=1e9+7;
ll sd=1717171717; 
int prand(){sd=sd*sd%INF; return sd;}
int gcd(int a,int b){if(!b)return a; return gcd(b,a%b);}
int main(){
	srand(time(0));
	int n; cin>>n;
	int l=n-1,r=INF,hh=58;
	while(l<r-1){
		int mid=(l+r)>>1,v;
		if(mid-1<=1000000000){
			hh--;
			printf("> %d\n",mid-1);
			fflush(stdout);
			scanf("%d",&v);
		}
		else v=0;
		if(v)l=mid;
		else r=mid;
	}
	printf("> %d\n",l);
	fflush(stdout);
	int vv; scanf("%d",&vv);
	if(vv)l++;
	printf("? %d\n",prand()%n+1);
	fflush(stdout);
	int v; scanf("%d",&v);
	int q=0;
	while(hh){
		hh--;
		printf("? %d\n",prand()%n+1);
		fflush(stdout);
		int u; scanf("%d",&u);
		int d=abs(u-v);
		if(!q||!d)q=q+d;
		else q=gcd(d,q);
	}
	printf("! %d %d\n",l-(n-1)*q,q);
	return 0;
}