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
int T;
int a[3][N],b[N];
char s[N];

int main(){
	scanf("%d",&T);
	rep(oo,T){
		int n; scanf("%d",&n);
		rep0(i,3)rep(j,2*n+1)a[i][j]=0;
		rep0(i,3){
			scanf("%s",s+1);
			rep(j,3*n)a[i][j]=s[j]=='1';
		}
		int nw1=1,nw2=1,nw3=1;
		rep(j,3*n){
			if(nw1<=2*n&&nw2<=2*n&&nw3<=2*n){
				int s1=(a[0][nw1]==1)+(a[1][nw2]==1)+(a[2][nw3]==1);
				int c=(s1>3-s1)?1:0;
				if(c==a[0][nw1])nw1++;
				if(c==a[1][nw2])nw2++;
				if(c==a[2][nw3])nw3++;
				putchar('0'+c);
			}
			else{
				int mx=0,c=0;
				if(nw1<=2*n&&nw1>mx){
					mx=nw1;
					c=a[0][nw1];
				}
				if(nw2<=2*n&&nw2>mx){
					mx=nw2;
					c=a[1][nw2];
				}
				if(nw3<=2*n&&nw3>mx){
					mx=nw3;
					c=a[2][nw3];
				}
				if(c==a[0][nw1]&&nw1<=2*n)nw1++;
				if(c==a[1][nw2]&&nw2<=2*n)nw2++;
				if(c==a[2][nw3]&&nw3<=2*n)nw3++;
				putchar('0'+c);
			}
		}
		puts("");
	}
	return 0;
}