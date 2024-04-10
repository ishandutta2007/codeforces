#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define SZ(x) (int)x.size()
#define MAXN 200010
#define MAXL 17
#define INF 1e9

int N,M,Ta,Tb,A,B,a,b;
vi Va, Vb;
priority_queue<int, vi, greater<int>> pq;
int T[MAXN];
int last_a, last_b;
int done[MAXN];

void out_pq(){
	vi V;
	while (SZ(pq)){
		cout<<pq.top()<<' ';
		V.pb(pq.top());
		pq.pop();
	}
	for (auto i : V)pq.push(i);
	cout<<'\n';
}

priority_queue<int, vi, greater<int> > islands;
set<int> aL[MAXN];
int E;
vpi V;
queue<int> SA, SB;

int main(){
	cin>>N>>M>>A>>B;
	last_a = N;
	last_b = N+M;
	if (A>=M||B>=N){
		cout<<"No";return 0;
	}
	int row1 = N;

	for (int i=1;i<=A;++i){
		cin>>a;
		Va.pb(a);
		SA.push(a);
		++T[a];
	}
	if (A==0){
		Va.pb(N);
		SA.push(N);
		++T[N];
	}
	for (int i=1;i<=B;++i){
		cin>>b;
		Vb.pb(b);
		SB.push(b);
		++T[b];
	}
	reverse(ALL(Va));
	reverse(ALL(Vb));

	for (int i=1;i<=N+M;++i){
		if (!T[i])pq.push(i);
	}
	// out_pq();
	cout<<"Yes\n";
	int tot=N+M;
	while (SZ(pq) && tot > 2){
		int t = pq.top();pq.pop();
		if (t<=N)--row1;
		if (row1 == 0 && t <=N)continue;
		// cout<<"RMV "<<t<<' '<<tot<<' '<<row1<<'\n';
		--tot;
		done[t] = 1;
		while(done[last_a])--last_a;

		if (t <= N){
			if (SZ(Vb)){
				int p = Vb.back();Vb.pop_back();
				V.pb(t,p);
				++E;
				--T[p];
				if (!T[p])pq.push(p);
			}else{
				++E;
				V.pb(t,last_b);
			}
		}else{
			if (SZ(Va)){
				int p = Va.back();Va.pop_back();
				++E;
				V.pb(t, p);
				--T[p];
				if (!T[p])pq.push(p);
			}else{
				++E;
				V.pb(t,last_a);
			}
		}
	}
	V.pb(last_a, last_b);
	assert(SZ(V) == N+M-1);
	
	for (auto i : V){
		aL[i.f].insert(i.s);
		aL[i.s].insert(i.f);
	}
	for (int i=1;i<=N+M;++i)if(SZ(aL[i]) == 1)islands.push(i);
	vi res;
	for (int i=1;i<=N+M-2;++i){
		int t = islands.top();islands.pop();
		int p = *aL[t].begin();
		res.pb(p);
		aL[p].erase(t);
		if (SZ(aL[p]) == 1)islands.push(p);
	}
	// for (auto i : res)cout<<i<<' ';cout<<'\n';
	for (int i=0;i<SZ(res);++i){
		assert(res[i] == V[i].s);
		int t = res[i];
		if (SZ(SA) && SA.front()==t)SA.pop();
		if (SZ(SB) && SB.front()==t)SB.pop();
	}
	for (auto i : V){
		if (i.f > i.s)swap(i.f,i.s);
		assert(i.f <= N && i.s > N);
	}
	assert(SZ(SA)+SZ(SB) == 0);
	for (auto v : V)cout<<v.f<<' '<<v.s<<'\n';

}