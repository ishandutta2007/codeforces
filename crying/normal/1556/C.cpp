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
const ll MAXN=1e3+10,INF=1e18;
ll n,c[MAXN],sum[MAXN][MAXN],minn[MAXN][MAXN];
ll ans;
ll solve(ll l,ll r){
	if(l==r-1){
		return min(c[l],c[r]);
	}
	ll mn=minn[l+1][r-1],s=sum[l+1][r-1];
	l=c[l];r=c[r]; 
	if(mn<0){
		if(l<abs(mn))return 0;
		l+=mn;
		s-=mn;
	}
	if(s<0)return 0;
	if(r<s)return 0;
	r-=s;
	return min(l,r)+1;
}
int main(){
	cin>>n;
	rep(i,1,n){
		cin>>c[i];
	}
	rep(i,1,n){
		rep(j,i,n){
			sum[i][j]=sum[i][j-1];
			if(odd(j))sum[i][j]+=c[j];
			else sum[i][j]-=c[j];
			if(j==i)minn[i][j]=sum[i][j];
			else minn[i][j]=min(minn[i][j-1],sum[i][j]);
		}
	}
	rep(l,1,n){
		if(even(l))continue;
		rep(r,l+1,n){
			if(odd(r))continue;
			ans+=solve(l,r);
		}
	}
	cout<<ans<<endl;
}