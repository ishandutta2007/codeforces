#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
ll n,a[5],b[5];
ll ans1,ans2,val;
int main(){
	cin>>n>>a[1]>>a[2]>>a[3]>>b[1]>>b[2]>>b[3];
	ans2+=Min(a[1],b[2]);
	ans2+=Min(a[2],b[3]);
	ans2+=Min(a[3],b[1]);
	ans1+=Max(0,b[2]-a[2]-a[3]);
	ans1+=Max(0,b[3]-a[3]-a[1]);
	ans1+=Max(0,b[1]-a[2]-a[1]);
	printf("%lld %lld",ans1,ans2);
	return 0;
}