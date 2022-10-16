#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
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
const int MAXN=1e6+10;
int T,n,m,f[MAXN];
void solve(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)f[i]=0;   
	rep(j,1,m){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		f[b]=1;
	}
	int t=0;
	rep(i,1,n){
		if(!f[i] && !t)t=i;
	}
	rep(i,1,n){
		if(i!=t){
			printf("%d %d\n",i,t);
		}
	}
	
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}