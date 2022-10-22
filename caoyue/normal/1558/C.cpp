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
const int N=5007;
const int INF=1e9+7;
int T,n;
int p[N],xl[N*5];
int fd(int x){
	rep(i,n){
		if(p[i]==x)return i;
	}
}
void rev(int x){
	rep(i,x/2)swap(p[i],p[x-i+1]);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n)scanf("%d",&p[i]);
		bool fl=0;
		rep(i,n){
			if((p[i]^i)&1){
				fl=1;
				break;
			}
		}
		if(fl){
			puts("-1");
			continue;
		}
		int cnt=0;
		for(int i=n;i>1;i-=2){
			int w1=fd(i);
			xl[++cnt]=w1;
			rev(w1);
			int w2=fd(i-1)-1;
			xl[++cnt]=w2;
			rev(w2);
			int w3=fd(i-1)+1;
			xl[++cnt]=w3;
			rev(w3);
			int w4=3;
			xl[++cnt]=w4;
			rev(w4);
			int w5=i;
			xl[++cnt]=w5;
			rev(w5);
		}
		printf("%d\n",cnt);
		rep(i,cnt)printf("%d ",xl[i]);
		puts("");
	}
	return 0;
}