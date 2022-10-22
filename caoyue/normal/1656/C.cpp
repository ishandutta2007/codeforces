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
const int N=1e5+7;
const int INF=1e9+7;
int T,n;
int a[N];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
bool i0,i1,i2;
int main(){
	scanf("%d",&T);
	while(T--){
		i0=i1=i2=0;
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n){
			if(a[i]==0)i0=1;
			if(a[i]==1)i1=1;
			if(a[i]==2)i2=1;
		}
		if(!i1)puts("YES");
		else{
			bool fl=0;
			sort(a+1,a+n+1);
			REP(i,2,n){
				if(a[i]-a[i-1]==1)fl=1;
			}
			if(fl)puts("NO");
			else puts("YES");
		}
	}
	return 0;
}