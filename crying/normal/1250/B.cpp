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
const int MAXN=1010;
int n,ret[MAXN][MAXN];
void solve(int x,int y,int a){
	rep(i,x,x+n/2-1){
		rep(j,y,y+n/2-1){
			ret[i][j]=a;
			a+=4;
		}
	}
}
int main(){
	cin>>n;
	solve(1,1,0);
	solve(1,n/2+1,1);
	solve(n/2+1,1,2);
	solve(n/2+1,n/2+1,3);
	rep(i,1,n){
		rep(j,1,n){
			printf("%d ",ret[i][j]);
		}
		printf("\n");
	}
	return 0;
}