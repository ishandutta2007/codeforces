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
const ll MAXN = 300100;

ll N,T,Q,E,a,b,c,d;
ll A[MAXN], B[MAXN];
ll opt[MAXN];
vi V[MAXN];
vi R[MAXN];
ll sub,ans,tot;
vi rte;

void bfs(int st){
	queue<int> Q;
	Q.push(st);
	memset(A,-1,sizeof(A));
	A[st] = 0;
	while (SZ(Q)){
		int t = Q.front();Q.pop();
		for (auto v: R[t]){
			if (A[v] == -1){
				A[v] = A[t] + 1;
				B[v] = 1;
				Q.push(v);
			}else if (A[v] == A[t]+1){
				++B[v];
			}
		}
	}
}

int main(){
	cin>>N>>E;
	for (int i=0;i<E;++i){
		cin>>a>>b;
		R[b].pb(a);
	}
	cin>>T;
	for (int i=0;i<T;++i){
		cin>>a;
		rte.pb(a);
	}
	int dest = rte.back();
	bfs(dest);
	// for (int i=1;i<=N;++i)cout<<A[i]<<' '<<B[i]<<'\n';
	int minct=0;
	for (int i=0;i<T-1;++i){
		int a = rte[i];
		int b = rte[i+1];
		if (A[b] == A[a] - 1)continue;
		++minct;
	}
	int maxct = 0;
	for (int i=0;i<T-1;++i){
		int a = rte[i];
		int b = rte[i+1];
		if (A[b] == A[a] - 1 && B[a] == 1)continue;
		++maxct;
	}
	cout<<minct<<' '<<maxct;
}