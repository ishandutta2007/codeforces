#include <bits/stdc++.h>
using namespace std;
// #define int               long long
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

const long long INF=1e9;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1003;
const int NN=20004*N;

bool vis[10004][N];
int d[10004];
vector<int> tim[4000];

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,m){
		cin>>d[i];
	}
	sort(d,d+m);
	int g,r;
	cin>>g>>r;
	
	tim[0].pb(0);
	rep(vt,0,20004*N){
		for(int x:tim[vt%4000]){
			int td=x/N,t=x%N;
			if(td==m-1){
				cout<<vt;
				return;
			}
			if(vis[td][t])continue;
			// cout<<td<<" "<<t<<"\n";
			vis[td][t]=1;
			int wait=0;
			int tt=t;
			if(t==0){
				wait=r;
				if(td==0)wait=0;
				t=g;
			}
			
			if(td!=0 && d[td]-d[td-1]<=t){
				int curbest=vt+d[td]-d[td-1]+wait;
				if(curbest < NN)tim[curbest%4000].pb((td-1)*N+t-d[td]+d[td-1]);
			}
			
			if(td!=m-1 && d[td+1]-d[td]<=t){
				int curbest=vt+d[td+1]-d[td]+wait;
				if(curbest < NN)tim[curbest%4000].pb((td+1)*N+t-d[td+1]+d[td]);
			}
		}
		tim[vt%4000].clear();
	}
	
	cout<<-1;
	
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