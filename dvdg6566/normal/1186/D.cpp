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
#define MAXN 100100

ld A[MAXN];
ll N,cnt,tot;

int main(){
	// freopen("in.txt","r",stdin);
	cin>>N;
	for (int i=0;i<N;++i){
		cin>>A[i];
		if (floor(A[i]) != A[i])++cnt;
		tot += floor(A[i]);
	}
	assert(tot <= 0);
	for (int i=0;i<N;++i){
		cin>>A[i];
		if ((int)A[i] == A[i]){
			cout<<A[i]<<'\n';
		}
		else if (tot != 0){
			++tot;
			if (ceil(A[i]) == 0)cout<<"0\n";
			else cout<<ceil(A[i])<<'\n';
		}else cout<<floor(A[i])<<'\n';
	}
}