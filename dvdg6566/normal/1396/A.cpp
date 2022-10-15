#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
const int MAXN=201000;
const ll MOD=998244353;

vi V;
ll N,Q,T,E,K,M,a,b,c,d;
ll A[MAXN],B[MAXN];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=1;i<=N;++i)cin>>A[i];
	if(N==1){
		cout<<"1 1\n0\n1 1\n0\n1 1\n"<<-A[1]<<'\n';
		return 0;
	}
	
	ll k=N - (A[1] % N);
	cout<<"1 1\n"<<k<<'\n';
	A[1]+=k;

	cout<<"2 "<<N<<'\n';
	for(int i=2;i<=N;++i){
		ll p=(N+A[i]%N)%N;
		A[i] += p*(N-1);
		cout<<p*(N-1)<<' ';
	}
	cout<<'\n';
	cout<<"1 "<<N<<'\n';

	for(int i=1;i<=N;++i)cout<<-A[i]<<' ';
}