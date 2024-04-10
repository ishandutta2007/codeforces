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
const ll MAXN=200100;
const ll MAXK=16000000;
const ll INF = 1e9;
const ll MOD = 1e9+7;

int A[MAXN];
int sz[MAXN];
int N,K,a,b;
int R;
vi V[MAXN];
int p[MAXN];
int par(int x){return (p[x]==x)?x:p[x]=par(p[x]);}

int main(){
	cin>>N>>K;
	for(int i=1;i<=N;++i){
		cin>>A[i];
		sz[A[i]]++;
		V[A[i]].pb(i);
	}
	R=N-1;
	for(int i=1;i<N;++i)if(A[i]==A[i+1])--R;
	cout<<R<<'\n';
	for(int i=1;i<=K;++i)p[i]=i;
	for(int i=1;i<K;++i){
		cin>>a>>b;
		a=par(a);b=par(b);
		if(sz[a]<sz[b])swap(a,b);
		// cerr<<"Merge "<<b<<" into "<<a<<'\n';
		for(auto i:V[b]){
			if(A[i+1]==a)--R;
			if(A[i-1]==a)--R;
		}
		for(auto i:V[b]){
			V[a].pb(i);
			A[i]=a;
		}
		p[b]=a;
		sz[a]=sz[b]=sz[a]+sz[b];
		cout<<R<<'\n';
	}
}