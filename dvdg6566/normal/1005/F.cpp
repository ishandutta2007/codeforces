#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 310000
#define MAXL 18

int N,M,K;
vpi E;
int a,b;
int dst[MAXN];
vi V[MAXN];
vpi P[MAXN];

queue<int> Q;
void bfs(int x){
	Q.push(x);
	while(SZ(Q)){
		int t=Q.front();Q.pop();
		for (auto v:V[t])if(!dst[v]){
			dst[v]=dst[t]+1;
			Q.push(v);
		}
	}
}

int mem[MAXN];
int out[MAXN];

int main(){
	cin>>N>>M>>K;
	for (int i=0;i<M;++i){
		cin>>a>>b;
		E.pb(a,b);
		V[a].pb(b);
		V[b].pb(a);
	}
	dst[1] = 1;
	bfs(1);
	for (int w=0;w<M;++w){
		pi i=E[w];
		if (dst[i.f] + 1 == dst[i.s])P[i.s].pb(i.f,w);
		else if (dst[i.s] + 1 == dst[i.f])P[i.f].pb(i.s,w);
	}
	vi chk;
	int w = 1;
	for (int i=2;i<=N;++i){
		if (SZ(P[i]) == 1){
			mem[P[i][0].s] = 1;
			continue;
		}
		if (w>=K){
			mem[P[i][0].s] = 1;
			continue;
		}
		w *= SZ(P[i]);
		chk.pb(i);
	}
	if (w >= K)cout<<K<<'\n';
	else cout<<w<<'\n';
	for (int i=0;i<min(w,K);++i){
		memset(out,0,sizeof(out));
		for (int i=0;i<M;++i)out[i]=mem[i];
		ll t = i;
		for (auto i : chk){
			ll w = SZ(P[i]);
			ll tmp = t % w;
			ll ind = P[i][tmp].s;
			out[ind] = 1;
			t /= w;
		}
		for (int i=0;i<M;++i)cout<<out[i];cout<<'\n';
	}
}