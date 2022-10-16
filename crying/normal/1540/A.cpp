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
const int MAXN=1e5+10;
ll T,n,d[MAXN],a[MAXN],sum[MAXN],sum2[MAXN],ans;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		rep(i,1,n){
			cin>>d[i];
		}
		sort(d+1,d+1+n);
		rep(i,1,n-1)a[i]=d[i+1]-d[i];
		rep(i,1,n-1){
			sum[i]=sum[i-1]+a[i];
		}
		rep(i,1,n-1){
			sum2[i]=sum2[i-1]+sum[i];
		}
		sum[n]=sum2[n]=0;
		ans=sum[n-1];
		rep(i,1,n-1){ans-=(sum[i]*i-sum2[i-1]);}
		cout<<ans<<endl;
	}

	return 0;
}