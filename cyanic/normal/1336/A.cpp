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

const int N=200005;
int val[N],sz[N],n,K,a,b;
vi e[N];
ll ans;

void dfs(int u,int fa,int d){
	sz[u]=1;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs(v,u,d+1);
		sz[u]+=sz[v];
	}
	val[u]=d-sz[u];
}

int main(){
	read(n),read(K);
	rep(i,1,n-1){
		read(a),read(b);
		e[a].pb(b),e[b].pb(a);
	}
	dfs(1,0,1);
	sort(val+1,val+n+1,greater<int>());
	rep(i,1,K) ans+=val[i];
	cout<<ans<<endl;

	return 0;
}