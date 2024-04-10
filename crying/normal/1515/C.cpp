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
const ll MAXN=1e5+10,INF=1e18;
ll T,n,m,x,ans[MAXN],s[MAXN];
pi w[MAXN];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>x;
		rep(i,1,n){
			cin>>w[i].fr;w[i].se=i;ans[i]=0;s[i]=0;
		}
		sort(w+1,w+1+n);
		rep(i,1,n){
			ans[w[i].se]=i%m+1;
		}
		ll maxn=-INF,minn=INF;
		rep(i,1,n)s[ans[w[i].se]]+=w[i].fr;
		rep(i,1,m)maxn=Max(maxn,s[i]),minn=Min(minn,s[i]);
		if(maxn-minn>x){
			printf("NO\n");continue;
		}
		printf("YES\n");
		rep(i,1,n)printf("%lld ",ans[i]);
		printf("\n");
	}

	return 0;
}