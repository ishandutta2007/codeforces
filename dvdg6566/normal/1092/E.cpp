#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
#define MAXN 200100

vi V[MAXN];
int dst[MAXN];
vpi cents; // Insert (centroid, longer half pair)
int ans;
int N,E,a,b;
vi cur;
vi opt;

void dfs(int x, int p){
	cur.pb(x);
	for (auto v:V[x])if(v!=p){
		dst[v] = dst[x] + 1;
		dfs(v,x);
	}
}

int main(){
	cin>>N>>E;
	for (int i=0;i<E;++i){
		cin>>a>>b;
		V[a].pb(b);
		V[b].pb(a);
	}
	memset(dst,-1,sizeof(dst));
	for (int i=1;i<=N;++i)if(dst[i]==-1){
		cur.clear();opt.clear();
		dst[i] = 0;
		dfs(i,-1);
		int furthest = -1;
		int wgt = -1;
		for (auto x:cur)if(dst[x] > wgt){
			furthest = x;wgt = dst[x];
		}
		cur.clear();
		dst[furthest]=0;
		dfs(furthest,-1);
		furthest = -1;
		wgt = -1;
		for (auto x:cur)if(dst[x] > wgt){
			furthest = x;wgt = dst[x];
		}
		ans = max(ans,wgt);
		int tar = wgt/2;
		for (auto x:cur){
			if (dst[x] == tar){opt.pb(x);}
		}
		
		dst[furthest]=0;
		dfs(furthest,-1);
		for (auto i : opt){
			if (dst[i] == wgt-tar){
				cents.pb(wgt-tar,i);
				break;
			}
		}

	}
	// for (auto i : cents)cout<<i.f<<' '<<i.s<<'\n';
	sort(ALL(cents));reverse(ALL(cents));
	vpi out;
	int rt = cents[0].s;
	for (int i=1;i<SZ(cents);++i){
		int cnode = cents[i].s;
		int clen = cents[i].f;
		ans = max(ans, cents[0].f + clen+1);
		out.pb(cnode,rt);
	}
	if (SZ(cents) >= 3){
		ans = max(2+cents[1].f+cents[2].f,ans);
	}
	cout<<ans<<'\n';
	for (auto i:out)cout<<i.f<<' '<<i.s<<'\n';
}