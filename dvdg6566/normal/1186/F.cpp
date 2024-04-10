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
#define SZ(x) (int)x.size()
#define MAXN 1001000

set<int> A[MAXN];
int N,M,a,b;
deque<pi> V,out;
int deg[MAXN],deg2[MAXN];

void dfs(int x,int c){
	if (SZ(A[x]) == 0)return;
	int b = *A[x].begin();
	A[x].erase(b);
	A[b].erase(x);
	M--;
	if (c == 1)V.pb(mp(b,x));
	else V.push_front(mp(b,x));
	dfs(b,c);
}

int main(){
	// freopen("in.txt","r",stdin);
	cin>>N>>M;
	for (int i=1;i<=M;++i){
		cin>>a>>b;
		A[a].insert(b);
		A[b].insert(a);
		++deg[a];++deg[b];
	}
	int P=M;
	int ct = 1;
	while(M){
		while(SZ(A[ct]) == 0){++ct;}
		dfs(ct,0);
		dfs(ct,1);
		for (int i=0;i<SZ(V);i+=2){
			out.pb(V[i]);
		}
		if (SZ(V) % 2 == 0)out.pb(V.back());
		V.clear();
	}
	cout<<SZ(out)<<'\n';
	// assert(SZ(out) <= (N+P+1)/2);
	for (auto i :out){
		cout<<i.f<<' '<<i.s<<'\n';
		++deg2[i.f];
		++deg2[i.s];
	}
	cout<<'\n';
	for (int i=1;i<=N;++i){
		assert((1+deg[i])/2 <= deg2[i]);
		// cout<<(1+deg[i])/2<<' '<<deg2[i]s<<'\n';
	}
}