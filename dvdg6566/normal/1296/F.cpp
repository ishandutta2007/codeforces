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
#define SZ(x) (int)x.size()
#define f first
#define s second
#define MAXN 5010

vpi V[MAXN];

vector<pair<int, pi>> E;
int N,a,b,w,X;
int out[MAXN];
queue<int> Q;

int dfs(int x, int p){
	if (x == b)return 1;
	int c = 0;
	for (auto v : V[x])if (v.f!=p){
		if (dfs(v.f,x)){
			Q.push(v.s);
			return 1;
		}
	}
	return 0;
}

int main(){
	cin>>N;
	for (int i=0;i<N-1;++i){
		cin>>a>>b;
		V[a].pb(b,i);V[b].pb(a,i);
	}
	cin>>X;
	while (X--){
		cin>>a>>b>>w;
		E.pb(mp(w, mp(a,b)));
	}
	sort(ALL(E));
	reverse(ALL(E));
	for (auto x:E){
		a = x.s.f;
		b = x.s.s;
		dfs(a,-1);
		bool done = 0;
		int minn = 1e6;
		while (SZ(Q)){
			int t = Q.front();Q.pop();
			minn = min(minn, out[t]);
			if (out[t])continue;
			// cout<<"Setting "<<t<<" to "<<x.f<<'\n';
			out[t] = x.f;
			done = 1;
		}
		if (!done && minn != x.f){
			cout<<-1;
			return 0;
		}
	}
	for (int i=0;i<N-1;++i){
		if (out[i] == 0)out[i] = 1e6;
		cout<<out[i]<<' ';
	}
}