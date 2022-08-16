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

const long long INF=1e16;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=3e5+5;

int parent[N],siz[N],total[N];
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
	total[parent_b] += total[parent_a];
	siz[parent_b]+=siz[parent_a];
	parent[parent_a]=parent_b;
	return;
}
void cleardsu(int n){
	for(int i=0;i<=n;i++){
		parent[i]=i;
		siz[i]=1;
		total[i] = 0;
	}
}


int h[N];
int b[N];
int vis[N];

void solve(){
	int n;
	cin >> n;
	
	cleardsu(n+2);
	
	set<pii,greater<pii> > s;
	
	rep(i,1,n+1){
		cin >> h[i];
		s.insert({h[i],i});
	}
	h[0] = n + 2;
	h[n+1] = n + 3;
	b[0] = INF;
	b[n+1] = INF;
	s.insert({h[0],0});
	s.insert({h[n+1],n+1});
	rep(i,1,n+1){
		cin >> b[i];
	}
	
	int ans = 0;
	
	while(!s.empty()){
		auto cur = *s.begin();
		s.erase(s.begin());
		int x = cur.sc;
		vis[x] = 1;
		total[x] = b[x];
		// cout << x << " ---> \n";
		
		if(x > 0 && x <= n){
			// try merge
			int l = 0, r = 0;
			if(vis[x-1]){
				l = total[findParent(x-1)];
			}
			if(vis[x+1]){
				r = total[findParent(x+1)];
			}
			
			amax(total[x],max(-l,-r));
			
			if(vis[x-1]){
				unionNodes(x,x-1);
			}
			if(vis[x+1]){
				unionNodes(x,x+1);
			}
			
		}
	}
	
	int par = findParent(n+1);
	cout << total[par] - 2 * INF;
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