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

const int N=200005;



int n;
int sqn;
vector<int> v[N],facs[N];
int a[N];
int ans;
int vis[N];

map<int, int> m[N];

int dfs2(int z,int p,int g){
	if(vis[z]){
		if(m[z].count(g))return m[z][g];
		else return 0;
	}
	vis[z]=1;
	for(int f:facs[z]){
		int am=0,bm=0;
		for(int x:v[z]){
			if(x==p)continue;
			int t=dfs2(x,z,f);
			if(t>=am){
				bm=am;
				am=t;
			}
			else if(t>=bm){
				bm=t;
			}
		}
		ans=max(ans,am+bm+1);
		m[z][f]=am+1;
	}
	return dfs2(z,p,g);
}

void solve(){
	cin>>n;
	sqn=sqrt(n);
	rep(i,1,n+1){
		cin>>a[i];
		int t=a[i];
		for(int j=2;j*j<=t;j++){
			if(t%j==0)facs[i].pb(j);
			while(t%j==0)t/=j;
		}
		if(t!=1)facs[i].pb(t);
	}
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs2(1,1,0);
	cout<<ans;
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