#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>
std::istream& operator>>(std::istream& in,pair<T1,T2> &a)
{
	in>>a.fr>>a.sc;
	return in;
}
template<typename T1,typename T2>
std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a)
{
	out<<a.fr<<" "<<a.sc;
	return out;
}

const int N=1e5+5;
int n,m,r[N],ans;

set<int> s[N],v[N];


vector<int> adj[N];int vis[N];
int col[N];
void dfs(int z,int p,int c){
	vis[z]=1;
	col[z]=c;
	for(int x:adj[z]){
		if(x==p)continue;
		if(vis[x]){
			if(col[x]==col[z]){
				ans=1;
				return;
			}
			else{
				continue;
			}
		}
		dfs(x,z,!c);
		if(ans)return;
	}
}

void solve(){
	cin>>n>>m;
	rep(i,0,n)cin>>r[i];
	rep(i,0,m){
		int k;
		cin>>k;
		rep(j,0,k){
			int t;
			cin>>t;
			t--;
			s[i].insert(t);
			v[t].insert(i);
		}
	}
	rep(i,0,n){
		if(r[i]){
			if(sz(v[i])==2){
				int a=*v[i].begin();
				int b=*v[i].rbegin();
				s[a].erase(i);
				s[b].erase(i);
				while(!s[b].empty()){
					int k=*s[b].begin();
					s[b].erase(k);
					v[k].erase(b);
					if(s[a].count(k)){
						s[a].erase(k);
						v[k].erase(a);
					}
					else{
						s[a].insert(k);
						v[k].insert(a);
					}
				}
				v[i].clear();
			}
		}
	}
	
	rep(i,0,n){
		// cout<<i<<" "<<sz(v[i])<<"\n";
		if(r[i])continue;
		if(v[i].empty()){
			cout<<"NO";
			return;
		}
		if(sz(v[i])==2){
			int a=*v[i].begin();
			int b=*v[i].rbegin();
			adj[a].pb(b);
			adj[b].pb(a);
		}
	}
	rep(i,0,m){
		if(!adj[i].empty() && !vis[i]){
			dfs(i,i,0);
		}
	}
	
	if(ans){cout<<"NO";}
	else cout<<"YES";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}