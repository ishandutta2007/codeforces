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
const ll INF=2e18;
ll T,n,k;
ll power(ll a,ll n){
	if(n>60)return INF;
	if(n==0)return 1;
	ll tmp=power(a,n/2);tmp*=tmp;
	if(n&1)tmp*=a;return tmp;
}
void solve(){
	cin>>n>>k;
	if(k>power(2,n-1)){
		printf("-1\n");return;
	}
	int now=1;
	while(true){
		rep(i,1,n){
			if(i+now-1>n)break;
			if(k<=power(2,n-now-i)){
				per(j,now+i-1,now){
					printf("%d ",j);
				}
				now+=i;break;
			}else k-=power(2,n-now-i);
		}
		if(now>n)break;
	}
	printf("\n");
}
int main(){
	cin>>T;
	while(T--){
		solve();	
	}
	return 0;
}