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

const long long INF=1e9;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e5+5;

int parent[N],size[N],len[N];
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
	if(size[parent_a]>=size[parent_b]){
		swap(parent_a,parent_b);
	}
	size[parent_b]+=size[parent_a];
	len[parent_b] += len[parent_a];
	parent[parent_a]=parent_b;
	return;
}
void cleardsu(int n){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		size[i]=1;
	}
}

void solve(){
	int n,m,p,q;
	cin>>n>>m>>p>>q;
	cleardsu(n);
	rep(i,0,m){
		int x,y,l;
		cin>>x>>y>>l;
		unionNodes(x,y);
		len[findParent(x)] += l;
	}
	vector<int> pars;
	rep(i,1,n+1){
		pars.pb(findParent(i));
	}
	sort(all(pars));
	uniq(pars);
	if(sz(pars) < q || sz(pars) - p > q){
		cout<<"NO\n";
		return;
	}
	
	set<pii> z;
	
	for(int x:pars){
		z.insert({len[x],x});
	}
	
	vector<pii> edg;
	
	int make = sz(pars) - q;
	rep(i,0,make){
		pii a = *z.begin();
		z.erase(z.begin());
		pii b = *z.begin();
		z.erase(z.begin());
		unionNodes(a.sc,b.sc);
		edg.pb({a.sc,b.sc});
		int s = len[findParent(a.sc)];
		s++;
		amin(s,INF);
		len[findParent(a.sc)] += s;
		z.insert({len[findParent(a.sc)],findParent(a.sc)});
	}
	
	p -= make;
	if(p){
		int comp = -1;
		rep(i,1,n+1){
			if(size[findParent(i)] > 1){
				comp = findParent(i);
				break;
			}
		}
		if(comp == -1){
			cout<<"NO";
			return;
		}
		int x=0,y=0;
		rep(i,1,n+1){
			if(findParent(i) == comp){
				if(!x){
					x = i;
				}
				else{
					y = i;
					break;
				}
			}
		}
		rep(i,0,p){
			edg.pb({x,y});
		}
	}
	
	cout<<"YES\n";
	for(auto x: edg){
		cout<<x<<"\n";
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