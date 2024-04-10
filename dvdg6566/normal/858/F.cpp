#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 500100;
const ll INF = 1e18;
const ll MOD = 1e9+7;

vi V[MAXN];
int N,M,a,b,c,d;
vi T[MAXN];
int dst[MAXN];
int A[MAXN];
queue<pi>Q;
vector<pair<int,pi>>E;

int dfs(int x, int p){
	//cerr<<x<<' '<<p<<'\n';
	// 0 is if you have used yourself
	// 1 is if you have not used yourself
	vi tt;
	if (A[x]>0)tt.pb(A[x]);
	for (auto v:T[x])if(v!=p){
		int t = dfs(v,x);
		if (t==0)continue;
		tt.pb(v);
	}
	while (SZ(tt) >= 2){
		a=tt.back();tt.pop_back();
		b=tt.back();tt.pop_back();
		E.pb(mp(a,mp(x,b)));
		//cout<<a<<' '<<x<<' '<<b<<'\n';
	}
	if (SZ(tt) == 1 && p!=-1){
		E.pb(mp(tt[0], mp(x,p)));
		//cout<<tt[0]<<' '<<x<<' '<<p<<'\n';
		return 0;
	}
	else{
		return 1;
	}
}

int main(){
	cin>>N>>M;
	for (int i=0;i<M;++i){
		cin>>a>>b;
		V[a].pb(b);V[b].pb(a);
	}
	memset(dst,-1,sizeof(dst));
	for (int i=1;i<=N;++i)if(dst[i]==-1){
		Q.push(mp(i,-1));
		dst[i]=0;
		while (SZ(Q)){
			int x=Q.front().f;
			int p=Q.front().s;
			//cout<<x<<' '<<p<<'\n';
			if(p!=-1)T[p].pb(x);
			Q.pop();
			for (auto v:V[x])if(v!=p){
				if (dst[v] == -1){
					dst[v] = dst[x] + 1;
					Q.push(mp(v,x));
				}else if (x<v){
					if (A[x] == 0)A[x] = v;
					else{
						E.pb(mp(v,mp(x,A[x])));
						//cout<<v<<' '<<x<<' '<<A[x]<<'\n';
						A[x] = 0;
					}
				}
			}
		}
		dfs(i,-1);
	}
	cout<<SZ(E)<<'\n';
	for (auto i :E){
		cout<<i.f<<' '<<i.s.f<<' '<<i.s.s<<'\n';
	}
}