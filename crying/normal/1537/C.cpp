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
int T,n,h[MAXN];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		rep(i,1,n)cin>>h[i];
		sort(h+1,h+1+n);
		ll mind=1e18;
		rep(i,1,n-1)mind=Min(mind,h[i+1]-h[i]);
		rep(i,1,n-1){
			if(h[i]+mind==h[i+1]){
				printf("%d ",h[i]);
				rep(j,i+2,n)printf("%d ",h[j]);
				rep(j,1,i-1)printf("%d ",h[j]);
				printf("%d ",h[i+1]);
				printf("\n");
				break;
			}
		} 
	}
	return 0;
}