#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
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

const int N=0;

vector<int> v[34];
int xx[34],yy[34];
void dfs(int z,int p,int lvl,int pc){
	int cnt=0; // 0 up, 1 right, 2 down, 3 left
	for(int x:v[z]){
		if(x==p)continue;
		if(cnt == pc) cnt++;
		int tmpc;
		if(cnt == 0){
			xx[x]=xx[z];
			yy[x]=yy[z]+(1ll<<lvl);
			tmpc=2;
		}
		if(cnt == 1){
			xx[x]=xx[z]+(1ll<<lvl);
			yy[x]=yy[z];
			tmpc=3;
		}
		if(cnt == 2){
			xx[x]=xx[z];
			yy[x]=yy[z]-(1ll<<lvl);
			tmpc=0;
		}
		if(cnt == 3){
			xx[x]=xx[z]-(1ll<<lvl);
			yy[x]=yy[z];
			tmpc=1;
		}
		dfs(x,z,lvl-1,tmpc);
		cnt++;
	}
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
	rep(i,1,n+1){
		if(sz(v[i])>4){
			cout<<"NO";
			return;
		}
	}
	xx[1]=yy[1]=0;
	dfs(1,0,41,-1);
	cout<<"YES\n";
	rep(i,1,n+1){
		cout<<xx[i]<<" "<<yy[i]<<"\n";
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}