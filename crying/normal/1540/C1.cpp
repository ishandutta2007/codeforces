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
const int MAXN=110,MAXM=1e4+10,moder=1e9+7;
int n,c[MAXN],b[MAXN],q,x;
ll f[MAXN][MAXM],sum[MAXN],sum2[MAXN],ans;
int main(){
	cin>>n;
	rep(i,1,n)cin>>c[i];
	rep(i,1,n-1)cin>>b[i];
	cin>>q>>x;
	rep(i,1,n){
		sum2[i]=sum2[i-1]+c[i];
		sum[i]=i*x;
		rep(j,1,i-1){
			sum[i]+=(i-j)*b[j];
		}
	}
	f[0][0]=1;
	rep(i,0,n-1){
		rep(j,0,sum2[i]){
			ll L=Max(0,sum[i+1]-j),R=c[i+1];
			rep(k,L,R){
				f[i+1][j+k]=(f[i+1][j+k]+f[i][j])%moder;
			}
		}
	}
	ll L=Max(0,sum[n]),R=sum2[n];
	rep(i,L,R){
		ans=(ans+f[n][i])%moder;
	}
	cout<<ans<<endl;
	return 0;
}