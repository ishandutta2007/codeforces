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
#define mapit map<int,int>::iterator
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
#define pr pair
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
ll n,m,l[MAXN],ans[MAXN],sum,R;
int main(){
	cin>>n>>m;
	rep(i,1,m){
		cin>>l[i];
		if(i+l[i]-1>n){printf("-1");return 0;}
		sum+=l[i];
	}
	if(sum<n){printf("-1");return 0;}
	ans[1]=1;R=l[1];
	rep(i,2,m){
		ans[i]=i;
		R=Max(R,i+l[i]-1);
	}
	if(R>=n){
		rep(i,1,m)printf("%d ",ans[i]);
		return 0;
	}
	ans[m]=n-l[m]+1;
	R=ans[m]-1;
	per(i,m-1,1){
		if(ans[i]+l[i]-1>=R-1)break;
		ans[i]=R-l[i]+1;
		R=ans[i]-1;
	}
	rep(i,1,m)printf("%d ",ans[i]);
	return 0;
}