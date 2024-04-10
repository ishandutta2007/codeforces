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
const ll MAXK=100000;
const ll INF = 1e9;
const ll MOD = 1e9+7;

ll N,K,Q,L,R,Y,C,a,b,c;
ll A[MAXN];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>Q;
	while(Q--){
		cin>>N;
		for(int i=1;i<=N;++i)cin>>A[i];
		int z=1;
		int o=1;
		for(int i=1;i<=N;++i){
			if(A[i]==i)o=0;
			else z=0;
		}
		if(z){cout<<"0\n";continue;}
		deque<ll> dq;
		for(int i=1;i<=N;++i)dq.pb(A[i]==i);
		while(SZ(dq)&&dq[0]==1)dq.pop_front();
		while(SZ(dq)&&dq.back()==1)dq.pop_back();
		int t=1;
		for(auto i:dq)if(i==1)t=0;
		if(t==1)cout<<"1\n";
		else cout<<"2\n";
	}
}