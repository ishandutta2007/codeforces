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
#define MAXN 400100

int A[MAXN];
vi V[MAXN];
int N,M,T,a,b;
int bst[MAXN];

int ok(int x){
	memset(bst, 0, sizeof(bst));
	for (int i=1;i<=x;++i){
		for (auto t:V[i]){
			bst[t] = i;
		}
	}
	vpi V;
	int sv = 0;
	for (int i=1;i<=N;++i){
		if (!A[i])continue;
		if (bst[i] == 0)continue;
		V.pb(bst[i], A[i]);
	}
	sort(ALL(V));
	int lft = x;
	while (SZ(V)){
		pi t = V.back();
		V.pop_back();
		lft = min(lft, t.f);
		int use = min(lft, t.s);
		sv += use;
		lft -= use;
	}
	int tcost = T*2 - sv;
	if (tcost <= x)return 1;
	return 0;
}

int main(){
	cin>>N>>M;
	for (int i=1;i<=N;++i){cin>>A[i];T += A[i];}
	for (int i=1;i<=M;++i){
		cin>>a>>b;
		V[a].pb(b);
	}
	int l=T;
	int u=T*2;
	// for (int i=l;i<=u;++i){
	// 	cout<<i<<' '<<ok(i)<<'\n';
	// }
	while (u>l){
		int m=(l+u)/2;
		if (ok(m))u = m;
		else l = m+1;
	}
	cout<<l;
}