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
const int MAXN=3e5+10,mod=998244353;
ll n,m,l[MAXN],r[MAXN],a[30],b[30];
ll fact[MAXN],inv[MAXN];
ll cnt[MAXN],bad[MAXN],ans; 
ll sum[MAXN][50],tag[MAXN];
ll power(ll a,ll n){
	if(!n)return 1;
	ll tmp=power(a,n/2);tmp=tmp*tmp%mod;
	if(n&1)tmp=tmp*a%mod;
	return tmp;
}
ll C(ll n,ll m){
	return (m>n)?0:fact[n]*inv[m]%mod*inv[n-m]%mod;
}
ll getsum(ll cnt,ll L,ll R){
	//cntL,R
	return (sum[R][cnt]-sum[L-1][cnt]+mod)%mod; 
}
int main(){
	cin>>n>>m;
	rep(i,1,n){
		cin>>l[i]>>r[i];
		cnt[l[i]]++;cnt[r[i]+1]--;
	}
	rep(i,1,m){
		cin>>a[i]>>b[i];
		int L=Max(l[a[i]],l[b[i]]),R=min(r[a[i]],r[b[i]]);
		if(L>R)continue;
		bad[L]++;bad[R+1]--;  
	}
	fact[0]=1;inv[0]=1;
	rep(i,1,n){
		fact[i]=(fact[i-1]*i)%mod;
		inv[i]=power(fact[i],mod-2);
	}
	ll s1=0,s2=0;
	rep(i,1,n){
		s1+=cnt[i];s2+=bad[i];
		cnt[i]=s1;bad[i]=s2;
	}
	rep(j,0,m*2){
		rep(i,1,n){
			sum[i][j]=sum[i-1][j];
			if(cnt[i]>=j && i>=j){
				sum[i][j]=(sum[i][j]+C(cnt[i]-j,i-j))%mod;
			}
		}
	}
	ll rks=0,sz=0,L=1,R=n,ret=0,ppcnt=0;
	rep(i,0,(1<<m)-1){
		//
		rks++;sz=ret=0,ppcnt=0;
		L=1;R=n;
		rep(j,1,m){
			if(!(i&(1<<(j-1))))continue;
			ppcnt++;
			if(tag[a[j]]!=rks)sz++;
			if(tag[b[j]]!=rks)sz++;
			tag[a[j]]=tag[b[j]]=rks;
			//
			L=max(L,max(l[a[j]],l[b[j]]));
			R=min(R,min(r[a[j]],r[b[j]])); 
		}
		if(L>R)continue;
		ret=getsum(sz,L,R);
		if(even(ppcnt))ans=(ans+ret)%mod;
		else ans=(ans-ret+mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}