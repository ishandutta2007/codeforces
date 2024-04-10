#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define emp emplace
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 510;
const ll MAXK = 17;
const ll INF = 1e18;
const ll MOD = 1e9+7;

int N;
string S;
vi A;
unordered_map<ll,int> U;

int ask(int s, int e){
	if(e<s)return 0;
	if (s==e)return 1;
	if(U[s*MAXN+e]!=0)return U[s*MAXN+e];

	int ans=min(1+ask(s+1,e), 1+ask(s,e-1));
	for (int a=s+1;a<=e;++a)if(A[s]==A[a]){
		ans=min(ans,ask(s+1,a-1)+ask(a,e));
	}
	return U[s*MAXN+e]=ans;
}

int main(){
	cin>>N>>S;
	for (auto i:S){
		if(SZ(A)&&A.back()==i-'a')continue;
		A.pb(i-'a');
	}
	cout<<ask(0,SZ(A)-1);
}