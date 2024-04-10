#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
typedef long long ll;
typedef double db;
using namespace std;
const int MAXN=600,LCM=720720;
int n,m,a[MAXN][MAXN];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		rep(j,1,m){
			scanf("%d",&a[i][j]);
		} 
	}
	rep(i,1,n){
		rep(j,1,m){
			if((i+j)&1)printf("%d ",LCM);
			else printf("%d ",LCM+a[i][j]*a[i][j]*a[i][j]*a[i][j]);
		}
		printf("\n");
	}
	return 0;
}