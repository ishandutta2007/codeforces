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

const int N=2e5+5;

int p[N];
int c[N];
int vis[N];

void solve(){
	int n;
	cin>>n;
	rep(i,1,n+1)cin>>p[i];
	rep(i,1,n+1)cin>>c[i];
	rep(i,1,n+1)vis[i]=0;
	int len=INF;
	vector<int> cyc;
	rep(i,1,n+1){
		if(vis[i])continue;//cout<<"\n"<<i<<"I wala loop\n";
		cyc.clear();
		int j=i,t=0;
		bool k=1;
		do{
			if(c[i]!=c[j])k=0;
			j=p[j];
			t++;
			cyc.pb(j);
		}while(j!=i);
		if(k){
			cout<<"1\n";
			return;
		}
		amin(len,t);
		vector<int> fac;
		for(int j=2;j*j<=t;j++){
			if(t%j)continue;
			fac.pb(j);
			if(j*j!=t)fac.pb(t/j);
		}
		for(int f:fac){
			vector<int> z(f);
			rep(j,0,t){
				int e=cyc[j];//cout<<e<<" ";
				if(z[j%f]==0)z[j%f]=c[e];
				if(z[j%f]!=c[e])z[j%f]=-1;
			}
			//cout<<"\n";
			rep(j,0,f){
				if(z[j]!=-1)amin(len,f);
			}
		}
		for(int x:cyc)vis[x]=1;
	}
	cout<<len<<"\n";
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