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
const ll INF=2e16,MAXN=100;
ll x[MAXN],y[MAXN],tot,a1,a2,b1,b2;
ll sx,sy,t,ans;
int check(){
	ll prex=x[tot],prey=y[tot];
	//prex*a1+b1 <= INF
	//prey*a2+b2 <= INF
	if(prex>(INF-b1)/a1)return 0;
	if(prey>(INF-b2)/a2)return 0;
	return 1;
}
int main(){
	cin>>x[1]>>y[1]>>a1>>a2>>b1>>b2;
	cin>>sx>>sy>>t;
	tot=1;
	while(1){
		if(check()){
			tot++;
			x[tot]=x[tot-1]*a1+b1;
			y[tot]=y[tot-1]*a2+b2;
		}else break;
	}
	rep(i,1,tot){
		ll cost=abs(sx-x[i])+abs(sy-y[i]);
		rep(l,1,i){
			rep(r,i,tot){
				ll lcost=abs(x[i]-x[l])+abs(y[i]-y[l]);
				ll rcost=abs(x[i]-x[r])+abs(y[i]-y[r]);
				if(cost+lcost+rcost+min(lcost,rcost)<=t){
					ans=max(ans,(ll)r-l+1);
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}