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
const int N=3e5+7;
const int INF=1e9+7;
int T,n,k;
int a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		rep(i,n)scanf("%d",&a[i]);
		bool fl=0;
		int s=0;
		rep(i,n){
			if(a[i]>=k)s++;
			if(a[i]==k)fl=1;
		}
		if(!fl)puts("no");
		else if(s-1>=n-s)puts("yes");
		else{
			int ls=-INF,gg=0;
			rep(i,n){
				if(a[i]>=k){
					if(i-ls<3){
						gg=1;
						break;
					}
					ls=i;
				}
			}
			if(gg)puts("yes");
			else puts("no");
		}
	}
	return 0;
}