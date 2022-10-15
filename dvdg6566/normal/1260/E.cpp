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
#define SZ(x) (ll)x.size()
#define MAXN 270100
#define INF 1e9
#define MAXL 20

ll A[MAXN];
ll N,K,ans;
vpi V;
priority_queue<int, vi, greater<int> > pq;

int MSB(unsigned long long x){return 32-__builtin_clz(x);}

int main(){
	cin>>N;
	for (int i=1;i<=N;++i){
		cin>>A[i];
		if (A[i] == -1)K=i;
	}
	
	ll T = (1<<(MSB(K)-1));
	for (int i=T;i <=N;++i){
		if (i==K)continue;
		if (i > K)V.pb(i, A[i]);
		else V.pb(i,0);
	}
	// for (auto i:V)cout<<i.f<<' '<<i.s<<'\n';

	while (SZ(V)){
		ll L = SZ(V);
		ll T = (1<<(MSB(L)-1));
		pq.push(V.back().s);
		V.pop_back();
		ans += pq.top();
		pq.pop();
		for (int i=1;i<T;++i){pq.push(V.back().s);V.pop_back();}
	}
	cout<<ans<<'\n';
}