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
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
#define ub upper_bound
const ll MAXN=200100;

vpi V;
int A[MAXN],N,a,b;
priority_queue<int,vector<int>,greater<int>>Q;
stack<int> P;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=1;i<N;++i){
		cin>>a;
		A[a]++;
		P.push(a);
	}
	for(int i=1;i<=N;++i)if(!A[i])Q.push(i);
	
	while(SZ(P)){
		int t=Q.top();Q.pop();
		int p=P.top();P.pop();
		
		V.pb(p,t);
		--A[p];
		if(!A[p])Q.push(p);	
	}

	if(SZ(V) < N-1){
		cout<<-1;
		return 0;
	}
	cout<<Q.top()<<'\n';
	reverse(ALL(V));
	for(auto i:V)cout<<i.f<<' '<<i.s<<'\n';
}