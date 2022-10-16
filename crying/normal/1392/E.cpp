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
const ll MAXN=30;
ll n,q,a[MAXN][MAXN],k;
void dfs(ll i,ll j,ll k){
	printf("%lld %lld\n",i,j);
	if(i==n && j==n)return;
	if(i==n)dfs(i,j+1,k);
	else if(j==n)dfs(i+1,j,k);
	else{
		if(a[i+1][j]){
			if(a[i+1][j]&k)dfs(i+1,j,k);
			else dfs(i,j+1,k); 
		}else{
			if(a[i][j+1]&k)dfs(i,j+1,k);
			else dfs(i+1,j,k);
		}
	}
}
int main(){
	cin>>n;
	rep(i,1,n){
		rep(j,1,n){
			if(even(i))a[i][j]=0;
			else a[i][j]=1LL<<(i+j-2);
		}
	}
	rep(i,1,n){
		rep(j,1,n)printf("%lld ",a[i][j]);
		printf("\n");
	}
	cout<<endl;
	cin>>q;
	while(q--){
		cin>>k;
		dfs(1,1,k);
		printf("\n");
		cout<<endl;
	}
	return 0;
}