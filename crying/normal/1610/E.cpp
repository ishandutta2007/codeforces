#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
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
const ll MAXN=2e5+10,INF=1e18;
ll T,n,a[MAXN],ans=INF;
void solve(){
	scanf("%lld",&n);
	rep(i,1,n)scanf("%lld",&a[i]);
	if(n<=2){
		printf("0\n");return;
	}
	ans=n-2;
	rep(i,1,n-1){
		if(a[n]==a[i]){
			ans=min(ans,(ll)(i-1));
			break;
		}
		int u=upper_bound(a+1,a+1+n,a[i])-a;
		ll cnt=u-i+1,maxn=a[u];
		while(1){
			if(u==n)break;
			ll val=maxn*2-a[i];
			if(a[n]<val)break;
			cnt++;
			u=lower_bound(a+u+1,a+1+n,val)-a;
			maxn=a[u];
		}
		ans=min(ans,n-cnt);
	}
	printf("%lld\n",ans);
}
int main(){
	scanf("%lld",&T);
	while(T--){
		solve();
	}

	return 0;
}