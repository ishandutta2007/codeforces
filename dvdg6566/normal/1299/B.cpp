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
#define MAXN 200010

ll N,Q,T,a,b,c,d,e;
ll A[MAXN];
ll B[31];
vpi V;

int main(){
	cin>>N;
	if (N%2 == 1){
		cout<<"NO";
		return 0;
	}
	for (int i=0;i<N;++i){
		cin>>a>>b;
		V.pb(a,b);
	}
	V.pb(V[0]);
	int H = N/2;
	for (int i=0;i<H;++i){
		// (i, i+1)
		// (i+H, i+H+1)
		// cout<<V[i].f<<' '<<V[i].s<<' '<<i+1<<" must be parallel to "<<
		ll h = (V[i+1].s - V[i].s);
		ll w = (V[i+1].f - V[i].f);
		ll h2 = (V[i+1+H].s - V[i+H].s);
		ll w2 = (V[i+1+H].f - V[i+H].f);
		if (h*w2 != w*h2){
			cout<<"NO";
			return 0;
		}
		ll l1 = (V[i+1].f - V[i].f) * (V[i+1].f - V[i].f) + (V[i+1].s - V[i].s) * (V[i+1].s - V[i].s);
		ll l2 = (V[i+1+H].f - V[i+H].f) * (V[i+1+H].f - V[i+H].f) + (V[i+1+H].s - V[i+H].s) * (V[i+1+H].s - V[i+H].s);
		if (l1 != l2){
			cout<<"NO";
			return 0;
		}
		
	}
	cout<<"YES";
}