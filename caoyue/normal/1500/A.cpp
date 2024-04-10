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
const int M=1e7+7;
const int INF=1e9+7;
int n;
int a[N];
struct pir{int x,y;}p1[M],p2[M];
bool check(pir a,pir b){
	if(a.x==b.x||a.y==b.y||b.x==a.y||b.y==a.x)return 0;
	return 1;
}
bool find(int L,int R,int &x,int &y){
	rep(i,5000000)p1[i]=(pir){0,0};
	REP(i,L,R){
		REP(j,i+1,R){
			int t=a[i]+a[j];
			pir h=(pir){i,j};
			if(p1[t].x){
				if(check(h,p1[t])){
					puts("YES");
					printf("%d %d %d %d\n",i,j,p1[t].x,p1[t].y);
					return 1;
				}
				if(h.x==p1[t].x){
					x=h.y;
					y=p1[t].y;
				}
				if(h.x==p1[t].y){
					x=h.y;
					y=p1[t].x;
				}
				if(h.y==p1[t].x){
					x=h.x;
					y=p1[t].y;
				}
				if(h.y==p1[t].y){
					x=h.x;
					y=p1[t].x;
				}
				return 0;
			}
			else p1[t]=(pir){i,j};
		}
	}
}
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,5000000)p1[i]=p2[i]=(pir){0,0};
	if(n<=6400){
		bool fl=0;
		rep(i,n){
			REP(j,i+1,n){
				int t=a[i]+a[j];
				if(!p1[t].x){
					p1[t]=(pir){i,j};
				}
				else {
					pir h=(pir){i,j};
					if(check(p1[t],h)){
						puts("YES");
						printf("%d %d %d %d\n",p1[t].x,p1[t].y,h.x,h.y);
						fl=1;
						break;
					}
					else{
						if(!p2[t].x)p2[i]=h;
						else if(check(p2[t],h)){
							puts("YES");
							printf("%d %d %d %d\n",p2[t].x,p2[t].y,h.x,h.y);
							fl=1;
							break;
						}
					}
				}
			}
			if(fl)break;
		}
		if(!fl)puts("NO");
	}
	else{
		int x1,x2,y1,y2;
		if(!find(1,3200,x1,y1)){
			if(!find(3201,6400,x2,y2)){
				puts("YES");
				printf("%d %d %d %d\n",x1,x2,y1,y2);
			}
		}
	}
	return 0;
}