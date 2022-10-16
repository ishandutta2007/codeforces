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
const int MAXN=110;
int T,n,a[MAXN],minn,maxn;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		minn=maxn=1;
		rep(i,1,n)cin>>a[i];
		rep(i,2,n){
			if(a[minn]>a[i])minn=i;
			if(a[maxn]<a[i])maxn=i;
		}
		int L=min(minn,maxn),R=max(minn,maxn);
		int ans=L+(n-R+1);
		ans=min(ans,n-L+1);
		ans=min(ans,R);
		printf("%d\n",ans);
	}

	return 0;
}