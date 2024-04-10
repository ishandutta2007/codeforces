#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
// #define int               long long
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

int fx[]={1,0,-1,0};
int fy[]={0,1,0,-1};
const int N=1505;
int n,m,x,y;
int a[N][N];
int vis[N][N];
int vx[N][N];
int vy[N][N];
int ans;

void dfs(int i,int j){
	int ii=(i%n + n)%n;
	int jj=(j%m + m)%m;
	// cout<<i<<" "<<j<<" "<<ii<<" "<<jj<<"\n";
	if(!a[ii][jj])return;
	if(vis[ii][jj]){
		if(i!=vx[ii][jj] || j!=vy[ii][jj])ans=1;
		return;
	}
	vis[ii][jj]=1;
	vx[ii][jj]=i;
	vy[ii][jj]=j;
	rep(u,0,4){
		dfs(i+fx[u],j+fy[u]);
		if(ans==1)return;
	}
}

void solve(){
	cin>>n>>m;
	rep(i,0,n){
		string s;
		cin>>s;
		rep(j,0,m){
			if(s[j]!='#')a[i][j]=1;
			if(s[j]=='S')x=i,y=j;
		}
	}
	dfs(x,y);
	cout<<(ans?"Yes":"No");
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