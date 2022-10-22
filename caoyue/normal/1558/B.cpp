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
const int N=4e6+7;
const int INF=1e9+7;
ll a[N],c[N];
ll n,mod;

int main(){
	scanf("%lld%lld",&n,&mod);
	a[1]=1;
	rep(i,n){
		c[i]=(c[i]+c[i-1])%mod;
		a[i]=(a[i]+c[i])%mod;
		c[i+1]=(c[i+1]+a[i])%mod;
		for(int j=2;j<=n;j++){
			if(j*i>n)break;
			c[j*i]=(c[j*i]+a[i])%mod;
			if(j*i+j<=n)c[j*i+j]=(c[j*i+j]-a[i]+mod)%mod;
		}
	}
	printf("%lld\n",a[n]);
	return 0;
}