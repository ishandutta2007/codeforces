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
const ll MAXN=410;
ll n,f[MAXN][MAXN];
ll power[MAXN],ans,moder;
ll c[MAXN][MAXN];
int main(){
	cin>>n>>moder;
	power[0]=1;rep(i,1,n)power[i]=power[i-1]*2%moder;
	rep(i,1,n){
		f[i][0]=power[i-1];
	}
	c[0][0]=1;
	rep(i,1,n){
		c[i][0]=1;
		rep(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%moder;	
	}
	rep(i,2,n){
		rep(j,1,i-2){
			//ij
			per(k,i-1,2){
				//[k+1,i]k
				f[i][j]=(f[i][j]+f[k-1][j-1]*power[i-k-1]%moder*c[i-j][i-k]%moder)%moder;
			}
		}
	}
	rep(j,0,n)ans=(ans+f[n][j])%moder;
	cout<<ans;
	return 0;
}