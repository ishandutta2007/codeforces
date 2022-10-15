#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
#define ub upper_bound
const ll MAXN=200001;
const ll MOD=1e9+7;
const ll INF = 3e9;
priority_queue<pi> pq;

ll A[MAXN];
ll N;

int ask(){
	int turn=0;
	int pv=-1;
	while(SZ(pq)){
		pi t=pq.top();pq.pop();
		if(t.s == pv){
			if(!SZ(pq)){
				return turn;
			}
			pi x=pq.top();pq.pop();
			pq.push(t);
			--A[x.s];
			if(A[x.s])pq.push(mp(A[x.s],x.s));
			pv=x.s;
		}else{
			--A[t.s];
			if(A[t.s])pq.push(mp(A[t.s],t.s));
			pv=t.s;
		}
		turn ^= 1;
	}
	return turn;
}

int main(){
	ll T;cin>>T;
	while(T--){
		while(SZ(pq))pq.pop();
		cin>>N;
		for(int i=1;i<=N;++i){
			cin>>A[i];
			pq.push(mp(A[i],i));
		}
		if(ask())cout<<"T\n";
		else cout<<"HL\n";
	}

}