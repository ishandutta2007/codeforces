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
const int MAXN=210000;
const int MAXK=19;
const int INF = 1e9;
const ll MOD = 998244353;

int N,M,a,b;
int O[MAXN];
int A[MAXN];
int done[MAXN];
vpi V[MAXN];
vi out;
queue<int> Q;

int main(){
	cin>>N>>M;
	for (int i=1;i<=N;++i)cin>>O[i];
	for(int i=0;i<M;++i){
		cin>>a>>b;
		V[a].pb(b,i+1);
		V[b].pb(a,i+1);
	}
	for(int i=1;i<=N;++i){
		if(SZ(V[i]) <= O[i]){
			Q.push(i);
		}
		A[i]=SZ(V[i]);
	}
	while(SZ(Q)){
		int a = Q.front();Q.pop();
		// cout<<"Remove "<<a<<'\n';
		done[a] = 1;
		for (auto i:V[a]){
			int b = i.f;
			if(done[b])continue;
			out.pb(i.s);
			--A[b];
			if(A[b] == O[b])Q.push(b);
		}
	}
	if(SZ(out) < M){
		cout<<"DEAD";
		return 0;
	}
	reverse(ALL(out));
	cout<<"ALIVE\n";
	for(auto i:out)cout<<i<<' ';
}