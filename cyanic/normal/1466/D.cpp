#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
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

const int N=1000005;
int w[N],deg[N],n,u,v;
pii a[N];
ll ans;

void rmain(){
	read(n),ans=0;
	rep(i,1,n){
		read(w[i]);
		ans+=w[i];
		deg[i]=0;
	}
	rep(i,1,n-1){
		read(u),read(v);
		deg[u]++,deg[v]++;
	}
	rep(i,1,n){
		a[i]=mp(w[i],deg[i]-1);
	}
	printf("%lld",ans);
	int k=1;
	sort(a+1,a+n+1,greater<pii>());
	rep(i,1,n-2){
		for(;!a[k].se;k++);
		a[k].se--;
		ans+=a[k].fi;
		printf(" %lld",ans);
	}
	puts("");
}

int main(){
	int T; read(T);
	for(;T;T--) rmain();
	return 0;
}