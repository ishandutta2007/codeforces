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
const int MAXN=110;
ll T,n,m,t[MAXN],l[MAXN],r[MAXN];
void solve(){
	scanf("%lld%lld",&n,&m);
	rep(i,1,n){
		scanf("%lld%lld%lld",&t[i],&l[i],&r[i]);
	}
	ll L=m,R=m;
	rep(i,1,n){
		ll cnt=t[i]-t[i-1];
		L-=cnt;
		R+=cnt;
		L=max(L,l[i]);R=min(R,r[i]);
		if(L>R){
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}
int main(){
	scanf("%lld",&T);
	while(T--){
		solve();
	}

	return 0;
}