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
ll MOD = 1e9+7;

ll N,K,E,Q,a,b,c,d,t,ans,cnt;
ll A[MAXN];

pi query(){
	cout<<"? ";
	int e=0;
	for (int i=1;i<=N;++i)if(A[i]){
		++e;
		cout<<i<<' ';
	}
	assert(e == K);
	cout<<endl;
	cin>>a>>b;
	return mp(a,b);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>K;
	for (int i=1;i<=K;++i){
		A[i]=1;
	}
	pi cur = query();
	bool isabove = 0;
	A[N] = 1;
	A[cur.f] = 0;
	pi t = query();
	if (t.s > cur.s)isabove=1;
	A[cur.f] = 1;
	vi lower;
	vi upper;
	vi same;
	
	for (int i=1;i<=K;++i)if(i!=cur.f){
		A[i] = 0;
		pi t = query();
		if (t.s == cur.s)same.pb(i);
		if (t.s > cur.s)lower.pb(i);
		if (t.s < cur.s)upper.pb(i);
		A[i]=1;
	}
	// cout<<SZ(lower)<<' '<<SZ(same)<<' '<<SZ(upper)<<'\n';
	assert(min(SZ(upper), SZ(lower)) == 0);
	cout<<"! ";
	if (isabove){
		cout<<SZ(lower)+1;
	}else{
		cout<<SZ(same)+1;
	}
}