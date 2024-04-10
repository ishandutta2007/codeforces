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

const int N=0;

int n,m,k;
map<int, int> s[22][22];
map<int, int> r[22][22];
int a[22][22];

void dfs(int x,int y,int z){
	if(x+y>19 || x>=n || y>=m)return;
	z^=a[x][y];
	s[x][y][z]++;
	dfs(x+1,y,z);
	dfs(x,y+1,z);
}

void dfs2(int x,int y,int z){
	if(x+y<19 || x<0 || y<0)return;
	r[x][y][z]++;
	z^=a[x][y];
	dfs2(x-1,y,z);
	dfs2(x,y-1,z);
}
void solve(){
	cin>>n>>m>>k;
	rep(i,0,n)rep(j,0,m)cin>>a[i][j];
	dfs(0,0,0);
	if(n+m-2<20)cout<<s[n-1][m-1][k];
	else{
		dfs2(n-1,m-1,k);
		int c=0;
		rep(i,0,20){
			int j=19-i;
			if(i>=n || j>=m)continue;
			for(auto f:s[i][j]){
				c+=f.sc*r[i][j][f.fr];
			}
		}
		cout<<c;
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