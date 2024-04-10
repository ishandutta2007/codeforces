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
const ll MAXN = 700100;
const ll OFF = 100100;

ll N,T,Q,E,a,b,c,d;
ll A[MAXN], B[MAXN];
ll opt[MAXN];
vi V[MAXN];
ll sub,ans,tot;

int main(){
	cin>>N;
	for (int i=1;i<=N;++i)cin>>A[i];
	opt[OFF + A[1] - 1] = A[1];
	B[1] = A[1];
	for (int i=2;i<=N;++i){
		ll t = opt[OFF + A[i] - i];
		ll v = t + A[i];
		B[i] = v;
		opt[OFF + A[i] - i] = max(opt[OFF + A[i] - i], v);
	}
	cout<<*max_element(B+1,B+N+1);
}