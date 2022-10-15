#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end() 
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN=100100;
const ll MAXK=20;
const ll INF = 1e13;
const ll MOD = 1e9+7;

ll N,a,b,c,d,e,M,K,T;
int A[MAXN];
int B[MAXN];
int col[MAXN];
priority_queue<pi>pq;
vi ind[MAXN];
int tr;

typedef pair<int,pi> pp;
int tryrun(){
	vector<pp> tp;
	deque<pp> bt;
	for(int i=1;i<=N;++i)if(B[i]==-1){
		tp.pb(col[A[i]],mp(A[i],i));
		bt.pb(col[A[i]],mp(A[i],i));
	}
	if(tr==0)return 1;
	if(SZ(tp)==0)return 1;
	sort(ALL(tp));
	sort(ALL(bt));
	int r=bt.back().f;
	// cerr<<r<<'\n';
	for(int i=0;i<r;++i){
		bt.pb(bt[0]);
		bt.pop_front();
	}
	// for(auto i:tp)cout<<i.f<<' ';cout<<'\n';
	// for(auto i:bt)cout<<i.f<<' ';cout<<'\n';
	for(int i=0;i<SZ(tp);++i){
		int a=tp[i].s.s;
		int b=bt[i].s.s;
		
		if(A[a]==A[b]){
			if(col[A[a]]!=r)assert(0);
			continue;
		}

		--tr;
		B[b]=A[a];
		if(tr==0)break;
	}

	if(tr>0){
		for(int i=0;i<SZ(tp);++i){
			// cerr<<r<<' '<<tp[i].f<<' '<<bt[i].f<<'\n';
			if(tp[i].f!=r&&bt[i].f!=r)assert(0);
		}
		return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>N>>M>>K;
		int out=-1;
		for(int i=1;i<=N+1;++i)col[i]=0;
		for(int i=1;i<=N;++i){
			B[i]=-1;
			cin>>A[i];
			ind[A[i]].pb(i);
			col[A[i]]++;
		}
		tr=K-M;
		int exc=N-K;
		for(int i=1;i<=N+1;++i)if(col[i]==0){
			out=i; break;
		}
		while(SZ(pq))pq.pop();
		for(int i=1;i<=N+1;++i)if(col[i]){
			pq.push(mp(col[i],i));
		}
		int tot=N-M;
		while(M--){
			pi t=pq.top();pq.pop();
			int i=ind[t.s].back();ind[t.s].pop_back();
			B[i]=t.s;
			--col[t.s];
			if(col[t.s]){
				pq.push(mp(col[t.s],t.s));
			}
		}
		if(tryrun()){
			for(int i=1;i<=N;++i)if(B[i]==-1){
				--exc;
				B[i]=out;
			}
			assert(exc==0);
			cout<<"YES\n";
			for(int i=1;i<=N;++i)cout<<B[i]<<' ';cout<<'\n';
		}else{
			int bgst=*max_element(col,col+N+1);
			int offs=bgst*2-tot;
			// if(offs<exc)assert(0);
			cout<<"NO\n";
		}
	}
}