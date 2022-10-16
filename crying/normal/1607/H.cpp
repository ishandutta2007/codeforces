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
const int MAXN=2e5+10,MAXM=2e6+10;
int T,n,a[MAXN],b[MAXN],m[MAXN];
int vis[MAXM],ans;
vector<ppi>q[MAXM];
ll reta[MAXN];
struct S1{
	int l,r,idx;
	bool operator<(const S1& s2)const{
		if(l!=s2.l)return l<s2.l;
		return idx<s2.idx; 
	}	
};
struct S2{
	int l,r,idx;
	bool operator<(const S2& s2)const{
		if(r!=s2.r)return r<s2.r;
		return idx<s2.idx;
	}
};
multiset<S1>s1;
set<S2>s2;
void solve(int v){
	s1.clear();s2.clear();
	for(auto tmp:q[v]){
		int idx=tmp.fr,l=tmp.se.fr,r=tmp.se.se;
		s1.is(((S1){l,r,idx}));
		s2.is(((S2){l,r,idx}));
	}
	while(s2.size()){
		auto tmp=*s2.begin();
		int idx=tmp.idx,l=tmp.l,r=tmp.r;
		ans++;
		reta[idx]=a[idx]-r;
	//	break;
		while(s1.size()){
			auto tmp=*s1.begin();
			int idxx=tmp.idx,ll=tmp.l,rr=tmp.r;
			if(ll<=r){
				reta[idxx]=a[idxx]-r;
				s1.erase(((S1){ll,rr,idxx}));
				s2.erase(((S2){ll,rr,idxx}));
			}else break;
		}
	}
}
void solve(){
	ans=0;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d%d",&a[i],&b[i],&m[i]);
		q[a[i]+b[i]-m[i]].clear();
		vis[a[i]+b[i]-m[i]]=0;
	}
	rep(i,1,n){
		q[a[i]+b[i]-m[i]].pb(mp(i,mp(a[i]-min(a[i],m[i]),a[i]-m[i]+min(b[i],m[i]))));
	}
	rep(i,1,n){
		if(vis[a[i]+b[i]-m[i]])continue;
		vis[a[i]+b[i]-m[i]]=1;
		solve(a[i]+b[i]-m[i]);
	}
	printf("%d\n",ans);
	rep(i,1,n){
		printf("%lld %lld\n",reta[i],m[i]-reta[i]);
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}