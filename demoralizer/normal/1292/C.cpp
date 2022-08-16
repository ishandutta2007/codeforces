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

const int N=3005;
vector<int> v[N];
int s[N][N];
int p[N][N];
int dp[N][N];
int n;

int dfs(int z,int par,int op){
	int ans=1;
	for(int x:v[z]){
		if(x==par)continue;
		ans+=dfs(x,z,op);
	}
	p[op][z]=par;
	s[op][z]=ans;
	return ans;
}

int calc(int l,int r){
	if(l==r){
		return 0;
	}
	if(l>r){
		return calc(r,l);
	}
	int &ans=dp[l][r];
	if(ans!=-1)return ans;
	ans=s[r][l]*s[l][r]+max(calc(l,p[l][r]),calc(p[r][l],r));
	return ans;
}

void solve(){
	mem1(dp);
	cin>>n;
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	rep(i,1,n+1){
		dfs(i,i,i);
	}
	int ans=0;
	rep(i,1,n+1){
		rep(j,1,n+1){
			ans=max(ans,calc(i,j));
		}
	}
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