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
const int MAXN=1e5+10;
ll T,n,a[MAXN],b[MAXN],ans;
ll suma[MAXN],sumb[MAXN];
int check(ll lim){
	ll cnt=lim-(lim/4);
	ll vala=0,valb=0;
	valb=sumb[Min(n,cnt)];
	ll num=Max(0,lim-n);
	ll use=Min(num,cnt);
	vala=use*100+suma[Min(n,Max(0,cnt-use))];
	return vala>=valb;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		suma[0]=sumb[0]=suma[n+1]=sumb[n+1]=0;
		rep(i,1,n){
			cin>>a[i];
		}
		rep(i,1,n){
			cin>>b[i];
		}
		sort(a+1,a+1+n,greater<ll>());
		sort(b+1,b+1+n,greater<ll>());
		rep(i,1,n){
			suma[i]=suma[i-1]+a[i];
			sumb[i]=sumb[i-1]+b[i];
		}
		if(check(n)){
			printf("0\n");continue;
		}
		
		ll L=1,R=1e9,ret=0;
		while(L<=R){
			int mid=(L+R)>>1;
			if(check(n+mid)){
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