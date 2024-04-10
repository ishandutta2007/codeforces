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
const int MAXN=6010;
const db EPS=1e-6;
ll n,X[MAXN],Y[MAXN],ret;
ll f(ll x){return x*(x-1)*(x-2)/6;}
ll g(ll x){return x*(x-1)/2;}
map<ll,ll>bucket;
ll solve(ll x,ll y){
	return g(x)*y+g(y)*x;
}
int main(){
	scanf("%lld",&n);
	rep(i,1,n){
		scanf("%lld%lld",&X[i],&Y[i]);
		X[i]=(X[i]>>1)&1;
		Y[i]=(Y[i]>>1)&1;
		bucket[(X[i]<<1)|Y[i]]+=1; 
	}
	rep(i,0,3)ret+=f(bucket[i]);
	rep(i,0,3)rep(j,i+1,3){ll x=bucket[i],y=bucket[j];ret+=solve(x,y);}
	cout<<ret<<endl;
	return 0;
}