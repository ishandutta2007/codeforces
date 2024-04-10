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
int t,n,a[MAXN],nxt[MAXN],nxt2[MAXN];
int st[MAXN],top,st2[MAXN],top2;
int f[MAXN][20],g[MAXN][20],power[20],lg2[MAXN];
ll ans;
il ll dist(pi a,pi b){
	return abs(a.fr-b.fr)+abs(a.se-b.se);
}
il int bad(pi a,pi b,pi c){
	return dist(a,c)==dist(a,b)+dist(b,c);
}
int check(int l,int r){
	rep(x,l,r){
		rep(y,l,r){
			rep(z,l,r){
				if(x==y || x==z || y==z)continue;
				if(bad(mp(a[x],x),mp(a[y],y),mp(a[z],z)))return 0;
			}
		}
	}
	return 1;
}
int main(){
	power[0]=1;rep(i,1,19)power[i]=power[i-1]*2;
	rep(i,2,2e5){
		if(power[lg2[i-1]+1]==i)lg2[i]=lg2[i-1]+1;
		else lg2[i]=lg2[i-1];
	}
	cin>>t;
	while(t--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i];
		}
		ans=0;
		rep(i,1,n){
			rep(j,i,n){
				if(check(i,j)){
					ans++;		
				}else break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
5
6 9 1 9 6
*/