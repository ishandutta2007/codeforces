#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 1001000

ll cur,curchange;
string A,B;
ll change[MAXN],ans;

int main(){
	// freopen("in.txt","r",stdin);
	cin>>A>>B;
	int N=SZ(A);
	int M=SZ(B);
	for (int i=0;i<N-1;++i)if (A[i] != A[i+1])change[i] = 1;
	for (int j=0;j<M;++j)if (A[j] != B[j])++cur;
	for (int i=0;i<M;++i)curchange += change[i];
	// for (int i=0;i<N-1;++i)cout<<change[i]<<' ';cout<<'\n';
	if (cur%2==0)++ans;

	for (int i=1;i<=N-M;++i){
		// cout<<i<<' '<<i+M-1<<'\n';
		// curchange
		cur += curchange;
		curchange -= change[i-1];
		curchange += change[i+M-1];
		// cout<<i<<' ' <<change[i-1]<<' '<<change[i+M-1]<<' '<<curchange<<'\n';
		if (cur%2==0)++ans;
	}

	cout<<ans;
}