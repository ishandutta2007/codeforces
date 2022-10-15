#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb emplace_back
#define mp make_pair
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define lb lower_bound
#define up upper_bound
ll MOD = 1e9+7;
#define MAXN 300100

int p[MAXN];
int flip[MAXN];
pi sizes[MAXN];
vi V[MAXN];
pi A[MAXN];
int N,K,a,b;
int ans;
string S;
ll THROW = 300001;
ll WANT = 300002;

int par(int x){return (x == p[x])?x:p[x] = par(p[x]);}

int val(int x){
	if (x < THROW)return min(sizes[x].f, sizes[x].s);
	return sizes[x].f;
}

void merge(int a, int b, int f){
	if (par(a) == par(b))return;
	// cout<<"Merging "<<a<<" and "<<b<<'\n';
	// Merging A into B
	if (f == 0){ // No need to flip
		// cout<<"No flip\n";
		ans -= val(a)+val(b);
		p[a] = b;
		for (auto i : V[a]){
			// no change to flip
			V[b].pb(i);
		}
		sizes[b].f += sizes[a].f;
		sizes[b].s += sizes[a].s;
	}else{ // Needs to flip
		// cout<<"Flip\n";
		ans -= val(a)+val(b);
		p[a] = b;
		for (auto i : V[a]){
			// flip
			V[b].pb(i);
			flip[i] ^= 1;
		}
		sizes[b].f += sizes[a].s;
		sizes[b].s += sizes[a].f;
	}
	ans += val(b);
	// cout<<sizes[b].f<<' '<<sizes[b].s<<'\n';
}

int main(){
	cin>>N>>K;
	cin>>S;
	S = "0" + S;
	for (int i=1;i<=K;++i){
		cin>>a;
		for (int j=0;j<a;++j){
			cin>>b;
			if (A[b].f == 0)A[b].f = i;
			else A[b].s = i;
		}
	}
	// for (int i=1;i<=N;++i)cout<<A[i].f<<' '<<A[i].s<<'\n';
	for (int i=1;i<=K;++i){
		p[i] = i;
		sizes[i] = mp(1,0);
		V[i].pb(i);
	}

	p[THROW] = THROW;
	p[WANT] = WANT;

	for (int i=1;i<=N;++i){
		// cout<<"At "<<i<<'\n';
		int a = A[i].f;
		int b = A[i].s;
		// cout<<a<<' '<<b<<'\n';
		if (a == 0 && S[i] == '0'){
			assert(0);
		}
		if (a == 0 && S[i] == '1'){
			cout<<ans<<'\n';
			continue;
		}
		// cout<<(b == 0)<<'\n';
		if (b == 0 && S[i] == '1'){ // Make sure a is on
			// cout<<"Don't want "<<a<<'\n';
			int aflip = flip[a]^1;
			merge(par(a), THROW, aflip);
			// cout<<flip[a]<<'\n';
			cout<<ans<<'\n';
			continue;
		}
		if (b == 0 && S[i] == '0'){
			// cout<<"Want "<<a<<'\n';
			int aflip = flip[a];
			merge(par(a), WANT, aflip);
			// cout<<flip[a]<<'\n';
			cout<<ans<<'\n';
			continue;
		}
		if (par(a) == par(b)){
			// cout<<"OK\n";
			cout<<ans<<'\n';
			continue;
		}

		if (SZ(V[par(a)]) > SZ(V[par(b)]) && par(b) != WANT && par(b) != THROW)swap(a,b);
		if (par(a) == WANT || par(a) == THROW)swap(a,b);

		int target_same = (S[i] == '0');
		int aflip = flip[a];
		int bflip = flip[b];
		if ((aflip == bflip) == target_same)merge(par(a), par(b), 1);
		else merge(par(a), par(b), 0);
		cout<<ans<<'\n';
	}
}