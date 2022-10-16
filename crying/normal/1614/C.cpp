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
#define int ll
typedef double db;
using namespace std;
const ll mod=1e9+7,MAXN=2e5+10;
ll T;
ll n,m,ans,num[35],a[MAXN];
ppi s[MAXN];
ll power(ll a,ll n){
	if(!n)return 1;
	ll tmp=power(a,n/2);tmp=tmp*tmp%mod;
	if(n&1)tmp=tmp*a%mod;return tmp;
}
il void upd(int L,int R){
	a[L]++;a[R+1]--;
}
il void spread(){
	rep(i,1,n)a[i]+=a[i-1];
}
void Read(ll& num){
	char ch;
	while((ch=getchar())&&!isdigit(ch));
	num=ch-'0';
	while((ch=getchar())&&isdigit(ch))num=num*10+ch-'0';
}
void solve(){
	ans=0;Read(n);Read(m);
	rep(i,1,m){
		Read(s[i].se.fr);
		Read(s[i].se.se);
		Read(s[i].fr);
	}
	memset(num,0,sizeof num);
	rep(i,0,29){
		rep(j,1,n)a[j]=0;
		rep(j,1,m){
			if(s[j].fr&(1<<i))continue;
			upd(s[j].se.fr,s[j].se.se);
		}
		spread();
		rep(j,1,n)if(a[j]==0)num[i]++;
		if(num[i]>=1){
			ans=(ans+power(2,n-num[i])*power(2,num[i]-1)%mod*(1LL<<i)%mod)%mod;
		}
	} 
	printf("%lld\n",ans);
}
signed main(){
	cin>>T;
	while(T--){
		solve();
	}

	return 0;
}