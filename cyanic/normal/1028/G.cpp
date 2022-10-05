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

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const ll mx=10004205361450474ll;
const ll lim=10000ll;
ll dp[6];

ll dfs(int k,ll l){
	if(k==5) return l+min(lim,l)-1;
	int T=min(lim,l);
	if(T==lim&&dp[k]) return l+dp[k];
	ll las=l,p=0;
	rep(t,1,T+1){
		p=dfs(k+1,las);
		las=p+2;
	}
	if(T==lim) dp[k]=p-l;
	return p;
}

void solve(int k,ll l){
	int T=min(lim,l);
	if(k==5){
		printf("%d ",T);
		rep(i,1,T) printf("%lld ",l-1+i);
		fflush(stdout);
		return;
	}
	vector<ll> pos;
	ll las=l,p=0;
	rep(t,1,T+1){
		p=dfs(k+1,las);
		if(t<=T) pos.pb(p+1);
		las=p+2;
	}
	printf("%d ",T);
	for(auto x:pos) printf("%lld ",x);
	fflush(stdout);
	int ret; read(ret);
	if(ret==-1) exit(0);
	if(ret==0) solve(k+1,l);
	else solve(k+1,pos[ret-1]+1);
}

int main(){
	solve(1,1);
	return 0;
}