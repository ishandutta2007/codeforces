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
#define MAXN 1010000
#define MAXL 20

int p[MAXN][MAXL];
int depth[MAXN];
vi V[MAXN];
int N,K,S,a,b;
int used[MAXN];

void dfs(int x, int pa){
	for (auto v:V[x])if(v!=pa){
		p[v][0] = x;
		depth[v] = depth[x] + 1;
		dfs(v,x);
	}
}

int lca(int a, int b){
	if (a==b)return a;
	if (depth[a] < depth[b])swap(a,b);
	int h=depth[a] - depth[b];
	for (int i=0;i<MAXL;++i)if((1<<i)&h){
		a=p[a][i];
	}
	if(a==b)return a;
	assert(depth[a]==depth[b]);

	for (int i=MAXL-1;i>=0;--i){
		if(p[a][i] != p[b][i]){
			a=p[a][i];
			b=p[b][i];
		}
	}
	assert(p[a][0] == p[b][0]);
	return p[a][0];
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>K;
	K=N-K;
	for (int i=1;i<N;++i){
		cin>>a>>b;
		V[a].pb(b);V[b].pb(a);
	}
	memset(p,-1,sizeof(p));
	dfs(1,-1);
	for (int i=1;i<MAXL;++i){
		for (int j=2;j<=N;++j){
			if (p[j][i-1]!=-1)p[j][i] = p[p[j][i-1]][i-1];
		}
	}
	int l = N;
	used[N] = 1;
	int t = 1;
	// cout<<"Set "<<N<<" to used\n";

	for (int x=N-1;x>0;--x){
		// cout<<"Try "<<x<<'\n';
		if (used[x])continue;
		int nl = lca(x,l);
		// cout<<nl<<'\n';
		// cout<<x<<' '<<l<<' '<<nl<<'\n';
		int dst = 0;
		if (nl == l){
			int tx = x;
			for (int i=MAXL-1;i>=0;--i){
				if (depth[tx] < (1<<i))continue;
				int temp = p[tx][i];
				if (depth[temp] < depth[l])continue;
				if (used[temp])continue;
				dst += (1<<i);
				tx = temp;
			}
			if (tx != l){
				++dst;
				tx = l;
			}
			// New node is a child
		}else{
			dst = depth[x] + depth[l] - 2*depth[nl];
		}

		// cout<<"Distance is "<<dst<<'\n';
		if (dst + t > K)continue;

		// Find distance
		int y = x;
		while (l != nl){
			l=p[l][0];
			used[l] = 1;
			++t;
		}
		l=nl;
		while (y!=nl){
			if (used[y] == 0){
				// cout<<"Set "<<y<<" to used\n";
				used[y] = 1;
				++t;
			}
			else break;
			y = p[y][0];
		}
		if (used[y] == 0){
			// cout<<"Set "<<y<<" to used\n";
			used[y] = 1;
			++t;	
		}
	}
	for (int i=1;i<=N;++i){
		if (!used[i])cout<<i<<' ';
	}
}