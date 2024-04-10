#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<time.h>
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
ll n,ans=0;
ll a[N];

int main(){
	scanf("%I64d",&n);
	rep(i,n)scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	ll o=0;
	rep(i,n-1)if(a[i]==a[i+1])o++;
	if(o>1){
		puts("cslnb");
		return 0;
	}
	if(o==1){
		rep(i,n-1){
			if(a[i]==a[i+1]){
				if(a[i]==0){
					puts("cslnb");
					return 0;
				}
				if(i!=1&&a[i-1]==a[i]-1){
					puts("cslnb");
					return 0;
				}
				a[i]--;
			}
		}
		rep(i,n)ans+=(a[i]-i+1);
		if(ans&1)puts("cslnb");
		else puts("sjfnb");
		return 0;
	}
	rep(i,n)ans+=(a[i]-i+1);
	if(ans&1)puts("sjfnb");
	else puts("cslnb");
	return 0;
}