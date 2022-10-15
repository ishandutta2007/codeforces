#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define MAXN 2010

ll N;
ll C[MAXN];
ll A[MAXN];
vi V[MAXN];
int rt;
vi T[MAXN];
int ans[MAXN];

void solve(int x, int p){
	int sub = 1;
	for (auto v:V[x])if (v!=p){
		solve(v,x);
		sub += SZ(T[v]);
	}
	if (sub <= C[x]){
		cout<<"NO";
		exit(0);
	}
	if (SZ(T[x]) == C[x])T[x].pb(x);
	for (auto v:V[x])if (v!=p){
		for (auto t:T[v]){
			T[x].pb(t);
			if (SZ(T[x]) == C[x])T[x].pb(x);
		}
	}
	return;
}

int main(){
	cin>>N;
	for (int i=1;i<=N;++i){
		int a;
		cin>>a>>C[i];
		if (a == 0)rt = i;
		else{
			V[a].pb(i);
			V[i].pb(a);
		}
	}
	solve(rt,-1);
	int t = 1;
	for (auto i : T[rt])ans[i] = t, t++;
	cout<<"YES\n";
	for (int i=1;i<=N;++i)cout<<ans[i]<<' ';
}