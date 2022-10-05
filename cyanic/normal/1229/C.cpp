#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
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

const int N=100005;
int f[N],g[N],id[N],cc,n,m,Q,a,b;
vi e[N];
ll ans;

int main(){
	read(n),read(m);
	rep(i,1,m){
		read(a),read(b);
		if(a>b)swap(a,b);
		e[a].pb(b);
		g[a]++,f[a]++,f[b]++;
	}
	rep(i,1,n){
		ans+=(ll)g[i]*(f[i]-g[i]);
		id[i]=i;
	}
	cout<<ans<<endl;
	read(Q),cc=n;
	while(Q--){
		read(a);
		ans-=(ll)g[a]*(f[a]-g[a]);
		for(auto b:e[a])
			if(id[b]>id[a]){
				ans-=g[b],g[b]++;
				ans+=f[b]-g[b];
				e[b].pb(a);
			}
		e[a].clear(),g[a]=0;
		id[a]=++cc;
		printf("%lld\n",ans);
	}
	return 0;
}