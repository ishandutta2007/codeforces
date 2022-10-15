#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 410000
#define MAXL 18

vi V[MAXN];
int leav[MAXN];
int wgt[MAXN];
int T,N;
int a,b;
vi tmp;
int dst[MAXN];

void dfs(int x, int p){
	for (auto v:V[x])if(v!=p){
		dst[v] = dst[x] + wgt[v];
		dfs(v,x);
	}
}

int main(){
	cin>>T;
	while(T--){
		cin>>N;
		for (int i=1;i<=N;++i){
			leav[i] = wgt[i] = 0;
			V[i].clear();
			dst[i] = 0;
		}
		for (int i=1;i<N;++i){
			cin>>a>>b;
			V[a].pb(b);
			V[b].pb(a);
		}
		if (N==2){
			cout<<2<<'\n';
			continue;
		}
		for (int i=1;i<=N;++i)if(SZ(V[i]) == 1)leav[i] = 1;
		for (int i=1;i<=N;++i){
			if (!leav[i])++wgt[i];
			for (auto v : V[i]){
				if (leav[v])++wgt[i];
			}
			if (leav[i])continue;
			tmp.clear();
			swap(V[i], tmp);
			for (auto v : tmp)if(!leav[v]){
				V[i].pb(v);
			}
			if (SZ(V[i]) > 1)wgt[i] += SZ(V[i]) - 2; // If not leaf node then can add all except 2 nodes as "bonus"
			// cout<<i<<' '<<wgt[i]<<' ';cout<<'\n';
		}
		int rt = 1;
		while (leav[rt])++rt;
		assert(rt <= N);
		dst[rt] = wgt[rt];
		dfs(rt,-1);
		int newrt = max_element(dst, dst+N+1) - dst;
		// cout<<newrt<<'\n';
		for (int i=1;i<=N;++i)dst[i]=0;
		dst[newrt] = wgt[newrt];
		dfs(newrt,-1);
		// for (int i=1;i<=N;++i)cout<<dst[i]<<' ';cout<<'\n';
		cout<<*max_element(dst,dst+N+1)<<'\n';
	}
}