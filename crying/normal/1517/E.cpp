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
const int MAXN=2e5+10,mod=998244353;
ll t,n,a[MAXN],g[MAXN],sum[MAXN],ans;
ll query(ll L,ll R){
	return L<=R?sum[R]-sum[L-1]:0;
}
ll query(ll L,ll R,ll flag){
	if(flag){
		//
		if(even(R))R--;
		if(even(L))L++;
		return L<=R?g[R]-g[Max(0,L-2)]:0;
	}else{
		// 
		if(odd(R))R--;
		if(odd(L))L++;
		return L<=R?g[R]-g[Max(0,L-2)]:0;
	}
}
ll f(ll st,ll n,ll lim){
	ll ans=0;
	//c
	rep(ed,st,n-1){
		//edCP 
		ll s1,s2;
		//CP
		int L=1,R=(n-ed+1)/2,ret=0;
		while(L<=R){
			int mid=(L+R)>>1; 
			s1=query(st,ed-1),s2=0;
			//midCPval+lim
			if(odd(ed)){
				//CP 
				s1+=query(ed,ed+2*mid-1,1);
				s2+=query(ed,ed+2*mid-1,0);
			}else{
				//CP 
				s1+=query(ed,ed+2*mid-1,0);
				s2+=query(ed,ed+2*mid-1,1);				
			}
			s2+=query(ed+2*mid,n);
			if(s1<s2+lim){
				ret=mid;
				L=mid+1;
			}else{
				R=mid-1;
			}
		}
		ans=(ans+ret)%mod;
	} 
	return ans;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		g[0]=sum[0]=0;
		rep(i,1,n){
			cin>>a[i];
			g[i]=g[Max(0,i-2)]+a[i];
			sum[i]=sum[i-1]+a[i];
		}
		if(n==1){printf("1\n");continue;}
		ans=0;
		ans+=f(1,n,0); 
		ans+=f(1,n-1,-a[n]);
		ans+=f(2,n,a[1]); 
		if(n>2){
			ans+=f(2,n-1,a[1]-a[n]);
		}
		//PPPPCCCC
		rep(i,1,n){
			if(query(i+1,n) < query(1,i))ans++;	
		}
		printf("%lld\n",ans%mod);
	}

	return 0;
}