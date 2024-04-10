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
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=1e5+7;
const ll INF=1e9+7;
ll n,T;
char s[N];
ll a[N],t[60];

int main(){
	scanf("%I64d%I64d",&n,&T);
	scanf("%s",s+1);
	rep(i,n)a[i]=s[i]-'a';
	T-=(1ll<<a[n]);
	T+=(1ll<<a[n-1]);
	rep(i,n-2)T+=(1ll<<a[i]);
	rep(i,n-2)t[a[i]]++;
	if(T&1){
		puts("No");
		return 0;
	}
	if(T<0){
		puts("No");
		return 0;
	}
	rep0(i,50){
		if(T&(1ll<<(i+1))){
			if(!t[i]){
				puts("No");
				return 0;
			} 
			T^=(1ll<<(i+1));
			t[i]--;
		}
		t[i+1]+=t[i]/2;
	}
	if(T!=0)puts("No");
	else puts("Yes"); 
	return 0;
}