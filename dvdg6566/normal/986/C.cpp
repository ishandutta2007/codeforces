#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 5000000
#define MAXL 22

int memo[MAXN];
bool occ[MAXN];
int N,M,c,a;
queue<int> Q;
vi V;

void resolve(int x){
	if (memo[x] != -1)return;
	memo[x] = c;
	// cout<<"Setting "<<x<<" to "<<c<<'\n';
	if (occ[x])Q.push(x);
	for (int i=0;i<N;++i)if((1<<i) & x){
		resolve(x ^ (1<<i));
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>N>>M;
	for (int i=0;i<M;++i){
		cin>>a;
		occ[a] = 1;
		V.pb(a);
	}
	memset(memo,-1,sizeof(memo));
	for (auto i : V){
		if (memo[i] != -1)continue;
		int opp = (1<<N) - 1 - i;
		Q.push(opp);
		while(SZ(Q)){
			int x = Q.front();Q.pop();
			resolve((1<<N) - 1 - x);
		}
		++c;
	}
	cout<<c;
}