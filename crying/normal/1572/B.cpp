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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
const int MAXN=2e5+10;
int T,n,a[MAXN],sum[MAXN];
vector<int>ret;
void solve(int l,int r){
	per(i,r-2,l){
		int num=i-l+1;
		if(odd(num))ret.pb(i);
	}
	rep(i,l,r-2){
		int num=i-l+1;
		if(odd(num))ret.pb(i);
	}
}
void solve(){
	scanf("%d",&n);
	ret.clear();
	rep(i,1,n){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	if(sum[n]){
		printf("NO\n");return;
	}
	if(odd(n)){
		printf("YES\n");
		solve(1,n);
		printf("%d\n",(int)ret.size());
		for(auto v:ret)printf("%d ",v);
		printf("\n");
		return;
	}
	rep(i,1,n-1){if(sum[i])continue;
		if(even(i))continue;
		printf("YES\n");
		solve(1,i);
		solve(i+1,n);
		printf("%d\n",(int)ret.size());
		for(auto v:ret)printf("%d ",v);
		printf("\n");
		return;
	}
	printf("NO\n");
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}