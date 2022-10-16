#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
ll q,n,ans=0;
void solve(){
	ans=0;cin>>n;
	if(n<=10){
		rep(i,1,n)ans=max(ans,n+min((i*i-3*i)/2,n-2*i));
		printf("%lld\n",ans);
		return;
	}
	rep(i,1,10)ans=max(ans,n+min((i*i-3*i)/2,n-2*i));
	ll p=(-1+sqrt(1+8*n))/2;
	ans=max(ans,n+min((p*p-3*p)/2,n-2*p));
	p++;
	ans=max(ans,n+min((p*p-3*p)/2,n-2*p));
	printf("%lld\n",ans);
}
int main(){
	cin>>q;
	while(q--){
		solve();
	}

	return 0;
}