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
const int MAXN=1e5+10,mod=998244353;
ll T,n,a[MAXN];
ll f[MAXN],ff[MAXN],b[MAXN],bb[MAXN],ans;
void solve(){
	scanf("%lld",&n);
	rep(i,1,n){
		scanf("%lld",&a[i]);
	}
	ans=0;
	b[0]=bb[0]=0;
	per(i,n,1){
		//printf("i:%d\n",i);
		bb[0]=0;
		bb[++bb[0]]=a[i];
		ff[a[i]]=1;
		//calc the answer
		rep(j,1,b[0]){
			ll cmp=b[j];
		//	printf("f[%d][%lld]:%lld\n",i+1,cmp,f[cmp]);
			ll val=a[i]/((a[i]+cmp-1)/cmp);
			ans=(ans+((a[i]+cmp-1)/cmp-1)*i%mod*f[cmp])%mod;
			bb[++bb[0]]=val;
			ff[val]=(ff[val]+f[cmp])%mod;
		}
		//clear old answer
		rep(j,1,b[0])f[b[j]]=0;
		b[0]=0;
		//change new answer
		sort(bb+1,bb+1+bb[0]);
		bb[0]=unique(bb+1,bb+1+bb[0])-bb-1;
		rep(j,0,bb[0])b[j]=bb[j];
		rep(j,1,b[0])f[b[j]]=ff[b[j]];
		//clear tmp answer
		bb[0]=0;
		rep(j,1,b[0])ff[b[j]]=0;
	}
	printf("%lld\n",ans);
	rep(j,1,b[0])f[b[j]]=0;
	b[0]=0;
}
int main(){
	cin>>T;
	while(T--){
		solve();
	}

	return 0;
}