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
const ll MAXN=2010,INF=1e18;
ll n,d[MAXN],ans=INF,f[MAXN][MAXN];
map<int,int>cnt;
int main(){
	cin>>n;
	rep(i,1,n){
		cin>>d[i];
	}
	sort(d+1,d+1+n);
	rep(len,2,n){
		rep(i,1,n){
			int j=i+len-1;
			if(j>n)break;
			f[i][j]=Min(f[i+1][j]+d[j]-d[i],f[i][j-1]+d[j]-d[i]);
		}
	}
	cout<<f[1][n];
	return 0;
}