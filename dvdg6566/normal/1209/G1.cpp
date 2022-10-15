#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 210000
#define MAXL 18

pi B[MAXN];
int W[MAXN];
int A[MAXN];
int dp[MAXN];
int runsum[MAXN];
vi V;

int N,a;

int main(){
	cin>>N>>a;
	for (int i=1;i<=N;++i)cin>>A[i];
	for (int i=0;i<MAXN;++i)B[i] = mp(-1,-1);
	for (int i=1;i<=N;++i){
		int a = A[i];
		if (B[a].f == -1)B[a].f = i;
		B[a].s = i;
		++W[a];
	}
	int runtop = 0;
	int ans = N;
	for (int i=1;i<=N;++i){
		int a = A[i];
		V.pb(W[a]);
		int backnum = B[a].s;
		runtop = max(runtop, backnum);
		if (runtop == i){
			ans -= *max_element(V.begin(),V.end());
			V.clear();
		}
	}
	cout<<ans;
}