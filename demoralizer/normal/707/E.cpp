#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

const int N=2005;
const int Q=1e6+5;


struct garland:vector<vector<pii>>
{
	int len;
	bool on=1;
}g[N];

struct query
{
	int type;
	garland *gar;
	int x1,y1,x2,y2;
	int id;
}q[Q];

vector<query> qs[2005];
vector<query> qa[2005];

int ans[N][N];

struct fenwick
{
	#define SIZE   N
	#define LSB(i) ((i) & -(i)) // zeroes all the bits except the least significant one

	int A[SIZE];

	int operator[] (int i) // Returns the sum from index 1 to i
	{
		int sum = 0;
		while (i > 0) 
			sum += A[i], i -= LSB(i);
		return sum;
	}
	void update(int i, int k) // Adds k to element with index i
	{
		while (i < SIZE) 
			A[i] += k, i += LSB(i);
	}
	void clear(){
		mem0(A);
	}
}fw;


void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	
	rep(i,0,k){
		cin>>g[i].len;
		g[i].resize(n+2);
		rep(j,0,g[i].len){
			int x,y,w;
			cin>>x>>y>>w;
			g[i][x].pb({y,w});
		}
	}
	
	int z,cnt=0;
	cin>>z;
	
	rep(i,0,z){
		string s;
		cin>>s;
		if(s[0]=='S'){
			q[i].type=1;
			int x;
			cin>>x;
			q[i].gar=g+x-1;
		}
		else{
			q[i].id=cnt++;
			q[i].type=2;
			cin>>q[i].x1>>q[i].y1>>q[i].x2>>q[i].y2;
			qs[q[i].x1].pb(q[i]);
			qa[q[i].x2].pb(q[i]);
		}
	}
	
	rep(i,0,k){
		rep(j,1,n+1){
			for(auto z:qs[j]){
				ans[i][z.id]-=fw[z.y2]-fw[z.y1-1];
			}
			
			for(pii p:g[i][j]){
				fw.update(p.fr,p.sc);
			}
			
			for(auto z:qa[j]){
				ans[i][z.id]+=fw[z.y2]-fw[z.y1-1];
			}
		}
		fw.clear();
	}
	
	rep(i,0,z){
		if(q[i].type==1){
			q[i].gar->on^=1;
		}
		else{
			int pr=0;
			rep(j,0,k){
				if(g[j].on)pr+=ans[j][q[i].id];
			}
			cout<<pr<<"\n";
		}
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
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}