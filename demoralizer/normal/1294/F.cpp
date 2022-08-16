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

vector<int> v[200005];int vis[200005];
multiset<int> k[200005];
int d[200005];
int dfs(int z){
	vis[z]=1;
	for(int x:v[z]){
		if(vis[x])continue;
		k[z].insert(dfs(x));
		if(sz(k[z])>3)k[z].erase(k[z].begin());
	}
	if(sz(k[z])==0)return 1;
	d[z]=((*k[z].rbegin())+1);
	return ((*k[z].rbegin())+1);
}

int ans=0;
int ver=0;


int dfs2(int z,int u){
	vis[z]=2;
	k[z].insert(u);
	// int d=*k[z].rbegin();
	for(int x:v[z]){
		if(vis[x]==2)continue;
		auto it=k[z].rbegin();
		if(*it==d[x])it++;
		dfs2(x,*it+1);
	}
	
	k[z].insert(0);
	k[z].insert(0);
	k[z].insert(0);
	auto it=k[z].rbegin();
	int tans=0;
	// cout<<z<<" ";
	rep(i,0,3){
		tans+=*it;
		// cout<<*it<<" ";
		it++;
	}
	// cout<<z<<" "<<tans<<"\n";
	// ans=max(ans,tans);
	if(tans>ans && sz(v[z])>1 ){
		ver=z;
		ans=tans;
	}
}

pii dleaf(int z,int p,int d){
	pii r={d,z};
	for(int x:v[z]){
		if(x==p)continue;
		r=max(r,dleaf(x,z,d+1));
	}
	// cout<<z<<" "<<r<<"\n";
	return r;
}
void solve(){
	int n;
	cin>>n;
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);
	dfs2(1,0);
	cout<<ans<<"\n";
	// cout<<ver<<"\n";
	set<pii> kk;
	for(int x:v[ver]){
		kk.insert(dleaf(x,ver,0));
	}
	kk.insert({-5,ver});
	auto it=kk.rbegin();
	// int tans=0;
	// cout<<z<<" ";
	rep(i,0,3){
		cout<< (it->sc) <<" ";
		it++;
	}
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