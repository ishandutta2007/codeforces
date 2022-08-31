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

const int N=1e6+5;

int sum=0;
int s[N],r;
vector<int> v[N];
int t[N];
int ot[N];

void dfs(int z,int p){
	vector<int> ots;
	for(int x:v[z]){
		if(x==p)continue;
		dfs(x,z);
		s[z]+=s[x];
		if(ot[x])ots.pb(ot[x]);
	}
	s[z]+=t[z];
	if(sz(ots) >= 2){
		cout<<ots[0]<<" "<<ots[1];
		exit(0);
	}
	if(z!=r && s[z] == 2*sum/3 && sz(ots)){
		cout<<z<<" "<<ots[0];
		exit(0);
	}
	if(sz(ots)){
		ot[z]=ots[0];
	}
	if(s[z]==sum/3){
		ot[z]=z;
	}
}


void solve(){
	int n;
	cin>>n;
	
	rep(i,1,n+1){
		int x,y;
		cin>>x>>y;
		t[i]=y;
		v[x].pb(i);
		sum+=y;
	}
	r=v[0][0];
	if(sum%3){
		cout<<-1;
		return;
	}
	
	dfs(r,r);
	
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