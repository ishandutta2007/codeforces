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
ll T,n,m,xa,ya,xb,yb,a,b;
ll dist;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		cin>>xa>>ya>>xb>>yb;
		cin>>a>>b;
		dist=1e18;
		ll x=a,y=b;
		if(xa<=x && ya<=y){
			//
			if(b+(yb-ya)<=m){
				dist=Min(dist,y-ya);
			}
			// 
			if(a+(xb-xa)<=n){
				dist=Min(dist,x-xa);
			}
		}else{
			dist=0;
		}
		x=n-a,y=b;
		if(xb>=x && ya<=y){
			//
			if(b+(yb-ya)<=m){
				dist=Min(dist,y-ya);
			}
			// 
			if(a+(xb-xa)<=n){
				dist=Min(dist,xb-x);
			}
		}else{
			
			dist=0;
		}
		x=a;y=m-b;
		if(xa<=x && yb>=y){
			// 
			if(b+(yb-ya)<=m){
				dist=Min(dist,yb-y);
			}
			// 
			if(a+(xb-xa)<=n){
				dist=Min(dist,x-xa);
			}
		}else{
		//	printf("HERE (%lld,%lld) (%lld,%lld)\n",x,y,xa,ya);
			dist=0;
		}
		x=n-a;y=m-b;
		if(xb>=x && yb>=y){
			// 
			if(b+(yb-ya)<=m){
				dist=Min(dist,yb-y);
			}
			// 
			if(a+(xb-xa)<=n){
				dist=Min(dist,xb-x);
			}
		}else{
			dist=0;
		}
		if(dist==1e18)printf("-1\n");
		else printf("%.6f\n",(double)dist); 
	}

	return 0;
}
/*
5
8 5
2 1 7 4
4 2
*/