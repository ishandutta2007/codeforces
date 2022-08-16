#include "bits/stdc++.h"
using namespace std;
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

const int N=2e5+5;

pii p[N];
int s[N];
int a[N];
int b[N];
int oc[N];

vector<int> l[N];
int vis[N];

void solve(){
	int n,m;
	cin>>n>>m;
	set<int> coor;
	rep(i,0,n){
		cin>>p[i].fr;
		p[i].sc = i;
		coor.insert(p[i].fr);
	}
	int cnt = 0;
	map<int, int> com;
	for(int x:coor){
		oc[cnt] = x;
		com[x] = cnt++;
	}
	
	rep(i,0,n){
		p[i].fr = com[p[i].fr];
	}
	
	rep(i,0,m){
		cin>>s[i];
		int x = s[i];
		while(x != 1){
			if(com.count(x)) l[com[x]].pb(i);
			x = (x+1)/2;
		}
		if(com.count(1)) l[com[1]].pb(i);
	}
	sort(p,p+n,greater<pii>());
	
	rep(i,0,cnt){
		sort(all(l[i]),[&](int a,int b){
			return s[a] > s[b];
		});
	}
	
	int c = 0,u = 0;
	rep(i,0,n){
		pii x = p[i];
		while(sz(l[x.fr]) && vis[l[x.fr].back()]) l[x.fr].ppb();
		if(sz(l[x.fr])){
			int y = l[x.fr].back();
			l[x.fr].ppb();
			vis[y] = 1;
			b[x.sc] = y+1;
			c++;
			int z = s[y];
			while(z != oc[x.fr]){
				a[y]++;
				u++;
				z = (z+1)/2;
			}
		}
	}
	
	cout<<c<<" "<<u<<"\n";
	rep(i,0,m)cout<<a[i]<<" ";cout<<"\n";
	rep(i,0,n)cout<<b[i]<<" ";cout<<"\n";
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