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
const int N=707;
const int INF=1e9+7;
int n;
int a[N];
bool gra[N][N],q[N][N];
int gcd(int x,int y){if(!y)return x; return gcd(y,x%y);}
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)rep(j,n)if(gcd(a[i],a[j])!=1)gra[i][j]=1;
	rep(i,n)q[i][i]=1;
	rep(i,n){
		rep(j,n-i+1){
			rep0(k,i){
				if(!q[j+k][j]||!q[j+k][j+i-1])continue;
				if(i==n){
					printf("Yes\n");
					return 0;
				}
				if(gra[j+k][j-1])q[j-1][j+i-1]=1;
				if(gra[j+k][j+i])q[j+i][j]=1;
			}
		}
	}
	printf("No\n");
	return 0;
}