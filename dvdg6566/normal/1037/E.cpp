#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 200100

vpi edgeList;
set<int> V[MAXN];
int N,M,K,a,b;
int blk[MAXN];
queue<int> q;
int deg[MAXN];
int out[MAXN];

int main(){
	// freopen("in.txt","r",stdin);
	cin>>N>>M>>K;
	for (int i=1;i<=M;++i){
		cin>>a>>b;
		V[a].insert(b);
		V[b].insert(a);
		edgeList.pb(mp(a,b));
		++deg[a];
		++deg[b];
	}
	for (int i=1;i<=N;++i){
		if (deg[i] < K){
			blk[i] = 1;
			q.push(i);
		}
	}
	while (SZ(q)){
		int t = q.front();
		q.pop();
		deg[t]=0;
		for (auto v : V[t]){
			if (blk[v])continue;
			--deg[v];
			if (deg[v] < K){
				q.push(v);
				blk[v] = 1;
			}
		}
	}
	int ans = 0;
	for (int i=1;i<=N;++i)if(!blk[i])++ans;

	out[M]=ans;

	for (int i=M-1;i>=1;--i){
		int a=edgeList[i].f;
		int b=edgeList[i].s;
		V[a].erase(b);V[b].erase(a);
		if (blk[a]||blk[b]){
			out[i]=out[i+1];
			continue;
		}
		--deg[a];
		--deg[b];
		if (deg[a] < K){
			blk[a] = 1;
			q.push(a);
		}
		if (deg[b] < K){
			blk[b] = 1;
			q.push(b);
		}
		while (SZ(q)){
			int t = q.front();
			q.pop();
			--ans;
			for (auto v : V[t]){
				if (blk[v])continue;
				--deg[v];
				if (deg[v] < K){
					q.push(v);
					blk[v] = 1;
				}
			}
		}
		out[i]=ans;
	}
	for (int i=1;i<=M;++i)cout<<out[i]<<'\n';
}