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
const ll N=5e5+7;
const ll INF=1e9+7;
set<ll>S;
vector<ll>id[N];
char s[N];
ll nx[N];
ll n,Ans=0,nw=0;
ll S2(ll x){return x*(x+1)/2ll;}
void ins(ll x){
	set<ll>::iterator w=S.upper_bound(x);
	set<ll>::iterator v=w;
	v--;
	nw-=S2((*w)-(*v)-1);
	nw+=S2((*w)-x-1);
	nw+=S2(x-(*v)-1);
	S.insert(x);
}
void del(ll x){
	set<ll>::iterator w0=S.lower_bound(x);
	set<ll>::iterator w1=w0,w2=w0;
	w1--;
	w2++;
	nw-=S2((*w2)-x-1);
	nw-=S2(x-(*w1)-1);
	nw+=S2((*w2)-(*w1)-1);
	S.erase(x);
}
int main(){
	scanf("%I64d",&n);
	scanf("%s",s+1);
	S.insert(0);
	S.insert(n+1);
	nw=S2(n);
	rep(i,n)if(s[i]=='1')ins(i);
	for(ll i=n;i;i--){
		if(s[i]=='0')nx[i]=0;
		else{
			nx[i]=nx[i+1]+1;
			if(nx[i]+1<=n-i+1)id[nx[i]+1].push_back(i);
		}
	}
	rep(i,n){
		for(ll j=0;j<id[i].size();j++)del(id[i][j]);
		Ans=Ans+S2(n-i+1)-nw;
		set<ll>::iterator gg=S.lower_bound(n-i+2);
		gg--;
		nw-=S2(n-i+1-(*gg));
		if((*gg)!=n-i+1){
			nw+=S2(n-i-(*gg));
			S.insert(n-i+1);
		}
		S.erase(n-i+2);
	}
	printf("%I64d\n",Ans);
	return 0;
}