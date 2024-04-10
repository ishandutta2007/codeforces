#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

int n;
int a[1000005];
int l[1000005];
int r[1000005];
vector<int> ans;
vector<int> v[1000005];int vis[1000005];
void dfs(int z){
	vis[z]=1;
	vector<int> y;
	for(int x:v[z]){
		if(vis[x])continue;
		y.pb(x);
		dfs(x);
	}
	ans.pb(z);
	while(!y.empty())ans.pb(y.back()),y.ppb();
}


void solve(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	ans.pb(0);
	dfs(1);ans.pb(1);
	rep(i,1,2*n+1){
		if(l[ans[i]])r[ans[i]]=i;
		else l[ans[i]]=i;
	}
	rep(i,1,n+1){
		cout<<l[i]<<" "<<r[i]<<"\n";
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
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