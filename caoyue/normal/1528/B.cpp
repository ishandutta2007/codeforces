#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
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
const int mod=998244353;
const int Max=1000000;
int f[N],sf[N];

int main(){
	for(int i=1;i<=Max;i++)for(int j=i;j<=Max;j+=i)f[j]=(f[j]+1)%mod;
	rep(i,Max){
		f[i]=(f[i]+sf[i-1])%mod;
		sf[i]=(sf[i-1]+f[i])%mod;
	}
	int n; scanf("%d",&n);
	printf("%d\n",f[n]);
	return 0;
}