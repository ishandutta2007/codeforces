#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
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
#define MAXN 500100

int A[MAXN], nxt[MAXN], P[MAXN];
int N,a,b,Q;
vector<tuple<int,int,int>> queries;
int out[MAXN];

struct node{
	int s,e,m;
	pi v;
	node *l, *r;
	node(int _s, int _e): s(_s), e(_e){
		m=(s+e)/2;
		if (s==e){
			v=mp(-1,s);
		}else{
			l = new node(s,m);
			r = new node(m+1,e);
			v=mp(-1,-1);
		}
	}
	pi query(int x, int y){
		// if (0 == s && N == e){cout<<"Querying "<<x<<' '<<y<<'\n';}
		if (s == x && e == y){
			return v;
		}
		if (y <= m)return l->query(x,y);
		else if (x > m)return r->query(x,y);
		return merge(l->query(x,m), r->query(m+1,y));
	}
	void up(int x,int val){
		// if (s == 0 && e == N){
		// 	cout<<"Updating "<<x<<" to "<<val<<'\n';
		// }
		if (s == e){
			v.f=val;
			return;
		}
		if (x > m)r->up(x,val);
		else l->up(x,val);
		v = merge(l->v,r->v);
	}
	pi merge(pi a, pi b){
		if (a.f > b.f){
			return a;
		}else {
			return b;
		}
	}
}*root;

int main(){
	// freopen("in.txt","r",stdin);
	cin>>N;
	for (int i=1;i<=N;++i)cin>>A[i];
	for (int i=1;i<=N;++i)P[i]=MAXN;

	root = new node(0,N);
	cin>>Q;
	for (int i=0;i<Q;++i){
		cin >> a >> b;
		queries.pb(a,b,i);
	}
	sort(ALL(queries));
	int ind = Q-1;
	for (int i=N;i>0;--i){
		// Remove for nxt
		nxt[i] = P[A[i]];
		root->up(i, nxt[i]);
		if (nxt[i] != MAXN)root->up(nxt[i], 0);

		P[A[i]] = i;

		while (ind != -1 && get<0>(queries[ind]) == i){
			pi stop = root->query(i, get<1>(queries[ind]));
			if (stop.f > get<1>(queries[ind])){
				out[get<2>(queries[ind])] = A[stop.s];
			}
			--ind;
		}
	}

	for (int i=0;i<Q;++i)cout<<out[i]<<'\n';
}