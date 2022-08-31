#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=2e6+5;
const int K=2e6+5;
const int R=2e6+5;

int parent[N],siz[N];
int findParent(int i)
{
	if(parent[parent[i]]!=parent[i])
		parent[i]=findParent(parent[i]);
	return parent[i];
}
void unionNodes(int a,int b)
{
	int parent_a=findParent(a),parent_b=findParent(b);
	if(parent_a==parent_b)
		return;
	if(siz[parent_a]>=siz[parent_b]){
		swap(parent_a,parent_b);
	}
	siz[parent_b]+=siz[parent_a];
	parent[parent_a]=parent_b;
	return;
}
void cleardsu(int n){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		siz[i]=1;
	}
}

#define SIEVE
int lp[K+1];
vector<int> pr;
void sieve(){
	for (int i=2; i<=K; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=K; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

int a[R];
int vis[R];
set<pii> S;

void solve(){
	cleardsu(N - 1);
	int n,q;
	cin >> n >> q;
	rep(i,1,n+1){
		cin >> a[i];
		if(vis[a[i]]) continue;
		vis[a[i]] = 1;
		int x = a[i];
		while(x != 1){
			unionNodes(a[i],lp[x]);
			x /= lp[x];
		}
	}
	
	rep(zz,1,n+1){
		vector<int> pf;
		int x = a[zz] + 1;
		while(x != 1){
			pf.pb(lp[x]);
			x /= lp[x];
		}
		uniq(pf);
		int u = sz(pf);
		rep(i,0,u){
			rep(j,i+1,u){
				int x = findParent(pf[i]);
				int y = findParent(pf[j]);
				if(x > y) swap(x,y);
				if(x == y) continue;
				S.insert({x,y});
				S.insert({y,x});
			}
			int x = findParent(a[zz]);
			int y = findParent(pf[i]);
			if(x > y) swap(x,y);
			S.insert({x,y});
			S.insert({y,x});
		}
	}
	
	while(q--){
		int s,t;
		cin >> s >> t;
		s = a[s];
		t = a[t];
		if(findParent(s) == findParent(t)){
			cout << 0 << "\n";
			continue;
		}
		s = findParent(s);
		t = findParent(t);
		if(s > t) swap(s,t);
		if(S.count({s,t}) || S.count({t,s})){
			cout << 1 << "\n";
		}
		else{
			cout << 2 << "\n";
		}
	}
	
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}