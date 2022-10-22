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
char s[N];
ll n;

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	ll mx=0;
	rep0(i,26){
		rep0(j,26){
			ll nw=0,ans=0;
			rep(k,n){
				if(s[k]-'a'==j)ans+=nw;
				if(s[k]-'a'==i)nw++;
			}
			mx=max(mx,ans);
			mx=max(mx,nw);
		}
	}
	printf("%I64d\n",mx);
	return 0;
}