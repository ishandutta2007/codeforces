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
#define MAXN 200100

vi V[MAXN];
int T,N,a,b;
ll tot,sav;
priority_queue<int> pq;

int main(){
	cin>>T;
	while(T--){
		cin>>N;
		tot = 0;
		while(SZ(pq))pq.pop();
		for(int i=1;i<=N;++i){
			cin>>a>>b;
			tot += b;
			V[a].pb(b);
		}
		for (int i=0;i<N;++i){
			for (auto t:V[i]){
				pq.push(t);
				// cout<<t<<'\n';
			}
			V[i].clear();
			if (SZ(pq) == 0)continue;
			else tot -= pq.top(), pq.pop();
		}
		cout<<tot<<'\n';
	}
}