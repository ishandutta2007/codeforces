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
const int MAXN=1e6+10;
ll t,pos[4][MAXN],h,w;
ll ans1,ans2;
void solve(){
	cin>>w>>h;
	rep(i,0,3){
		cin>>pos[i][0];
		rep(j,1,pos[i][0])cin>>pos[i][j];
	}
	ans1=max(pos[0][pos[0][0]]-pos[0][1],pos[1][pos[1][0]]-pos[1][1])*h;
	ans2=max(pos[2][pos[2][0]]-pos[2][1],pos[3][pos[3][0]]-pos[3][1])*w;
	printf("%lld\n",max(ans1,ans2));
}
int main(){
	cin>>t;
	while(t--){
		solve();
	}


	return 0;
}