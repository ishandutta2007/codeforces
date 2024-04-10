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
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=2e5+7;
const ll INF=1e9+7;
ll n;
ll a[N];

int main(){
	cin>>n;
	rep(i,n)cin>>a[i];
	if(n==1){
		puts("1 1");
		cout<<-a[1]<<endl;
		puts("1 1");
		puts("0");
		puts("1 1");
		puts("0");
		return 0;
	}
	cout<<1<<" "<<1<<endl;
	cout<<-a[1]<<endl;
	cout<<2<<" "<<n<<endl;
	REP(i,2,n){
		ll t=(n-1)*a[i];
		cout<<t<<" ";
		a[i]+=t;
	}
	a[1]=0;
	cout<<endl;
	cout<<1<<" "<<n<<endl;
	rep(i,n)cout<<-a[i]<<" ";
	puts("");
	return 0;
}