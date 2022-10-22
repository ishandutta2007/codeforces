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
const int N=1e5+7;
const int INF=1e9+7;
int n;
int a[N],b[N],t[2][N];
bool v[N];
int main(){
	scanf("%d",&n);
	rep(i,n-1)scanf("%d",&a[i]);
	rep(i,n-1)scanf("%d",&b[i]);
	bool flag=0;
	rep0(x,2){
		bool fl=1;
		int nw=x;
		t[0][0]=x;
		rep(i,n-1){
			int hh;
			if(nw){
				if(b[i]&1)hh=1;
				else hh=0;
			}
			else{
				if(a[i]&1)hh=1;
				else hh=0;
			}
			if((a[i]&1)!=(hh|nw)){fl=0; break;}
			if((b[i]&1)!=(hh&nw)){fl=0; break;}
			nw=hh;
			t[0][i]=hh;
		}
		if(fl){flag=1; break;}
	}
	if(!flag){printf("NO\n"); return 0;}
	flag=0;
	rep0(x,2){
		bool fl=1;
		int nw=x;
		t[1][0]=x;
		rep(i,n-1){
			int hh;
			if(nw){
				if(b[i]&2)hh=1;
				else hh=0;
			}
			else{
				if(a[i]&2)hh=1;
				else hh=0;
			}
			if((a[i]&2)/2!=(hh|nw)){fl=0; break;}
			if((b[i]&2)/2!=(hh&nw)){fl=0; break;}
			nw=hh;
			t[1][i]=hh;
		}
		if(fl){flag=1; break;}
	}
	if(!flag){printf("NO\n"); return 0;}
	printf("YES\n");
	rep0(i,n)printf("%d ",t[0][i]+t[1][i]*2); 
	printf("\n"); 
	return 0;
}