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
const int MAXN=2e5+10;
int T,n,a[MAXN],cnt[30];
void solve(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(j,0,29)cnt[j]=0;
	rep(i,1,n)rep(j,0,29)if(a[i]>>j&1)cnt[j]++;
	rep(i,1,n){
		int flag=1;
		rep(j,0,29)if(cnt[j]%i)flag=0;
		if(flag)printf("%d ",i);
	}
	printf("\n");
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}