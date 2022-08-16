#include <bits/stdc++.h>
using namespace std;
// #define int               long long
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

const int N=(1<<20)+5;
const int K=5e5+5;

int a[K],b[K],vis[N];
vector<int> s[N];
vector<int> col[N];

int numtocol[N];
int nxt[N];

int parent[N+K],size[N+K];
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
	parent[parent_a]=parent_b;
	return;
}
void cleardsu(int n){
	for(int i=0;i<n;i++){
		parent[i]=i;
		size[i]=1;
	}
}

void dfs(int ver){
	int tmp = ver;
	
	do{
		vis[ver]=1;
		ver = nxt[nxt[ver]];
	}while(tmp != ver);
	
	ver = tmp;
	
	do{
		cout<<ver<<" "<<nxt[ver]<<" ";
		int c = numtocol[nxt[ver]];
		while(sz(col[c]) && vis[col[c].back()]){
			col[c].ppb();
		}
		if(sz(col[c])){
			dfs(col[c].back());
		}
		ver = nxt[nxt[ver]];
	}while(tmp != ver);
}

void solve(){
	int n;
	cin>>n;
	rep(i,0,n){
		cin>>a[i]>>b[i];
		
	}
	
	for(int bi=20;bi>=0;bi--){
		int B = (1<<bi);
		cleardsu(N+K);
		rep(i,0,B){
			s[i].clear();
			col[i].clear();
		}
		rep(i,0,n){
			s[a[i]%B].pb(i);
			s[b[i]%B].pb(i);
			numtocol[2*i+1] = a[i]%B;
			numtocol[2*i+2] = b[i]%B;
			vis[i]=0;
		}
		bool ex = 0;
		rep(i,0,n){
			if(vis[i])continue;
			int x=a[i]%B,y=b[i]%B;
			vis[i] = 1;
			unionNodes(i,K+x);
			unionNodes(i,K+y);
			col[x].pb(2*i+1);
			nxt[2*i+1] = 2*i+2;
			int last = 2*i+2;
			
			while(y!=x){
				while(sz(s[y]) && vis[s[y].back()]){
					s[y].ppb();
				}
				if(s[y].empty()){
					ex=1;
					break;
				}
				int id=s[y].back();
				unionNodes(id,i);
				if(a[id]%B == y){
					col[y].pb(2*id+1);
					y = b[id]%B;
					nxt[last] = 2*id+1;
					last = 2*id+2;
					nxt[2*id+1] = last;
				}
				else{
					col[y].pb(2*id+2);
					y = a[id]%B;
					nxt[last] = 2*id+2;
					last = 2*id+1;
					nxt[2*id+2] = last;
				}
				unionNodes(id,K+y);
				vis[id] = 1;
			}
			if(ex){
				break;
			}
			nxt[last] = 2*i+1;
		}
		if(ex){
			continue;
		}
		int comp = findParent(0);
		rep(i,0,n){
			if(findParent(i) != comp){
				ex = 1;
				break;
			}
		}
		if(ex){
			continue;
		}
		cout<<bi<<"\n";
		
		mem0(vis);
		dfs(1);
		// pri(a[0]%B);
		
		return;
	}
	// cout<<"0\n";
	// rep(i,1,2*n+1){
	// 	cout<<i<<" ";
	// }
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