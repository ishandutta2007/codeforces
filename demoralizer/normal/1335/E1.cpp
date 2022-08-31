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

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=2e5+5;

int ps[N][201];

int a[N];
vector<int> v[201];

void solve(){
	int n;
	cin>>n;
	rep(i,1,201){
		v[i].clear();
	}
	rep(i,1,n+1){
		rep(j,1,201){
			ps[i][j]=0;
		}
	}
	rep(i,1,n+1){
		cin>>a[i];
		v[a[i]].pb(i);
		ps[i][a[i]]=1;
		rep(j,1,201){
			ps[i][j]+=ps[i-1][j];
		}
	}
	int ans=0;
	rep(i,1,201){
		amax(ans,ps[n][i]-ps[0][i]);
		int l=sz(v[i]);
		rep(j,0,l/2){
			int L=v[i][j]+1,U=v[i][l-1-j]-1;
			if(L>U)continue;
			int k=1;
			rep(z,1,201){
				if(ps[U][k]-ps[L-1][k]<ps[U][z]-ps[L-1][z])k=z;
			}
			amax(ans,2*j+2+ps[U][k]-ps[L-1][k]);
		}
	}
	cout<<ans<<"\n";
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
	cin>>t;
	while(t--) solve();
	return 0;
}