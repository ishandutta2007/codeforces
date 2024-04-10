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
const int MAXN=5010;
ll n,a[MAXN],b[MAXN],f[MAXN][MAXN],ans;
ll sum[MAXN],suf[MAXN];
int main(){
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
	}
	rep(i,1,n){
		cin>>b[i];
	}
	rep(i,1,n){
		f[i][i]=a[i]*b[i];
	}
	rep(i,1,n){
		sum[i]=sum[i-1]+a[i]*b[i];
	}
	per(i,n,1){
		suf[i]=suf[i+1]+a[i]*b[i];
	}
	rep(len,2,n){
		rep(i,1,n){
			int j=i+len-1;if(j>n)break;
			f[i][j]=a[i]*b[j]+a[j]*b[i]+f[i+1][j-1]; 
		}
	}
	rep(i,1,n){
		rep(j,i,n){
			ans=Max(ans,sum[i-1]+suf[j+1]+f[i][j]);		
		}
	}
	printf("%lld",ans);
	return 0;
}