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
ll T,a[4],m;
void solve(){
	cin>>a[1]>>a[2]>>a[3]>>m;
	sort(a+1,a+4);
	ll minn=max(0LL,a[3]-a[2]-a[1]-1);
	ll maxn=a[1]+a[2]+a[3]-3;
	if(m>=minn && m<=maxn)printf("YES\n");
	else printf("NO\n");
}
int main(){
	cin>>T;
	while(T--){
		solve();
	}

	return 0;
}