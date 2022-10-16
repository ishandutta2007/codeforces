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
const int MAXN=2e5+10;
ll T,n,a[MAXN],g[MAXN][20],power[20],logn[MAXN];
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b); 
}
ll query(ll L,ll R){
	if(L<=R){
		ll len=R-L+1;
		len=logn[len];
		return gcd(g[L][len],g[R-power[len]+1][len]);
	}else{
		return gcd(query(L,n-1),query(0,R));
	}
}
int check(ll mid){
	ll val=query(0,mid);
	rep(i,1,n-1){
		if(query(i,(i+mid)%n)!=val)return 0;
	}
	return 1;
}
int main(){
	power[0]=1;
	rep(i,1,19)power[i]=power[i-1]*2;
	rep(i,1,2e5){
		logn[i]=logn[i-1];
		if(power[logn[i]+1]==i)logn[i]++;
	}
	cin>>T;
	while(T--){
		cin>>n;
		rep(i,0,n-1){
			cin>>a[i];
		}
		int flag=1;
		rep(i,1,n-1){
			if(a[i]!=a[0])flag=0;
		}
		if(flag){
			printf("0\n");continue;
		}
		rep(i,0,n-1){
			g[i][0]=a[i];
		}
		rep(j,1,19){
			rep(i,0,n-1){
				g[i][j]=gcd(g[i][j-1],g[(i+power[j-1])%n][j-1]);
			}
		}
		ll L=1,R=n-1,ret=0;
		while(L<=R){
			ll mid=(L+R)>>1;
			if(check(mid)){
				ret=mid;
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		printf("%lld\n",ret);
	}

	return 0;
}
/*
1
4
16 24 10 5
*/