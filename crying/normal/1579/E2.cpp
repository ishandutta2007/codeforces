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
int T,n,a[MAXN],b[MAXN],bucket[MAXN],tot,w[MAXN];
ll ans;
struct BIT{
	int tree[MAXN];
	void update(int x,int val){
		for(;x<=n;x+=lowbit(x))tree[x]+=val;
	}
	int query(int x){
		int ret=0;
		for(;x;x-=lowbit(x))ret+=tree[x];
		return ret;
	}
}tree;
void solve(){
	tot=ans=0;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);b[++tot]=a[i];
		w[i]=0;
	}
	sort(b+1,b+1+tot);
	tot=unique(b+1,b+1+tot)-b-1;
	rep(i,1,n){
		a[i]=lower_bound(b+1,b+1+tot,a[i])-b;
	}
	rep(i,1,n){
		w[i]=tree.query(a[i]-1);
		tree.update(a[i],1);
		ans+=min(w[i],i-1-w[i]-bucket[a[i]]);
		bucket[a[i]]++;
	}
	printf("%lld\n",ans);
	rep(i,1,n){
		tree.update(a[i],-1);
		bucket[a[i]]--;
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}