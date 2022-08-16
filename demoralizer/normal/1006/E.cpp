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

const int N=2e5+5;

vector<int> v[N];
vector<int> order;
int pos[N];
int szz[N];
int dfs(int z){
	pos[z]=sz(order);
	order.pb(z);
	int s=1;
	for(int x:v[z]){
		s+=dfs(x);
	}
	szz[z]=s;
	return s;
}
void solve(){
	int n,q;
	cin>>n>>q;
	rep(i,2,n+1){
		int p;
		cin>>p;
		v[p].pb(i);
	}
	dfs(1);
	rep(i,0,q){
		int u,k;
		cin>>u>>k;
		if(szz[u]<k)cout<<-1;
		else cout<<order[pos[u]+k-1];
		cout<<"\n";
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