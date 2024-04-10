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
const int MAXN=2e5+10,moder=1e9+7,LIM=2e5;
ll t,n,m;
ll cnt[10][10][MAXN];
ll ans,power[MAXN];
int main(){
	rep(i,0,9){
		cnt[i][i][0]=1;
	}
	rep(j,0,9){
		rep(i,1,LIM){
			rep(k,0,9){
				cnt[j][k][i]=cnt[j][(k+9)%10][i-1];
			}
			cnt[j][1][i]+=cnt[j][9][i-1];
			cnt[j][1][i]%=moder;
		}
	}
	power[0]=1;
	rep(i,1,LIM)power[i]=power[i-1]*2%moder;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		ans=0;
		while(n){
			ll val=n%10;
			rep(j,0,9){
				ans=(ans+cnt[val][j][m])%moder;
				//printf("")
			}
			n/=10;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
/*
1
1912 1
*/