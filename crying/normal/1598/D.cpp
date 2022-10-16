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
const ll MAXN=2e5+10;
ll T,n,a[MAXN],b[MAXN];
ll c1[MAXN],c2[MAXN];
void solve(){
	cin>>n;
	rep(i,1,n){
		cin>>a[i]>>b[i];
		c1[i]=c2[i]=0;
	}
	rep(i,1,n){
		c1[a[i]]++;c2[b[i]]++;
	}
	ll ans=0;
	ans=n*(n-1)*(n-2)/6;
	rep(i,1,n)ans-=(c1[a[i]]-1)*(c2[b[i]]-1);
	cout<<ans<<endl;
}
int main(){
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}