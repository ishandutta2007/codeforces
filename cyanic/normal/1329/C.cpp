#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=(1<<20)+5;
int a[N],b[N],h,g,n;
vector<pii> v[N];
ll sum;

int dfs(int x,int d){
	if(x*2>n){
		v[x].pb(mp(-a[x],x));
		return 0;
	}
	int lc=x*2,rc=lc+1;
	int mx=max(dfs(lc,d-1),dfs(rc,d-1));
	v[x].pb(mp(-a[x],x));
	v[x].resize(v[lc].size()+v[rc].size()+1);
	merge(v[lc].begin(),v[lc].end(),
		v[rc].begin(),v[rc].end(),next(v[x].begin()));
	while(-v[x].back().fi<mx) v[x].pop_back();
	if(d>0){
		b[v[x].back().se]=1;
		int ret=-v[x].back().fi;
		sum+=ret,v[x].pop_back();
		return ret;
	}
	return 0;
}

void rmain(){
	read(h),read(g),n=(1<<h)-1,sum=0;
	rep(i,1,n){
		read(a[i]);
		b[i]=0,v[i].clear();
	}
	dfs(1,g);
	printf("%lld\n",sum);
	per(i,n,1) if(!b[i]) printf("%d ",i);
	puts("");
}

int main(){
	int T; read(T);
	while(T--) rmain();
	return 0;
}