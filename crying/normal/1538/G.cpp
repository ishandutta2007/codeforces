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
ll T,x,y,a,b,ans;
ll check(ll mid){
	ll L=ceil((db)(y-mid*a)/(b-a));
	ll R=floor((db)(x-mid*b)/(a-b));
	if(max(L,0LL)<=min(R,mid))return 1;
	return 0;
}
int main(){
	cin>>T;
	while(T--){
		cin>>x>>y>>a>>b;
		if(a==b){
			printf("%lld\n",Min(x,y)/a);	
			continue;
		}
		if(a<b)swap(a,b);
		ll L=0,R=1e9,ret=0;
		while(L<=R){
			ll mid=(L+R)>>1;
			if(check(mid)){
				ret=mid;
				L=mid+1;
			}else{
				R=mid-1;
			}
		}
		cout<<ret<<endl;
	}

	return 0;
}