#include "bits/stdc++.h"
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

struct cmp
{
	bool operator() (pii a,pii b){
		return ((a.fr - a.fr/2)*a.sc) > ((b.fr - b.fr/2)*b.sc);
	}
};
multiset<pii,cmp> s[3];

const int N=1e5+5;
int sum;
vector<pair<int, pii>> v[N];
int dfs(int z,int p){
	int ans = 0;
	for(pair<int, pii> x:v[z]){
		if(x.fr==p)continue;
		int tmp = dfs(x.fr,z);
		s[x.sc.sc].insert({x.sc.fr,tmp});
		sum += tmp * x.sc.fr;
		ans += tmp;
	}
	if(!ans) ans = 1;
	return ans;
}

void solve(){
	sum = 0;
	s[1].clear();
	s[2].clear();
	int n,w;
	cin>>n>>w;
	rep(i,1,n+1) v[i].clear();
	rep(i,1,n){
		int x,y,z,c;
		cin>>x>>y>>z>>c;
		v[x].pb({y,{z,c}});
		v[y].pb({x,{z,c}});
	}
	
	dfs(1,0);
	int ans = INF;
	
	vector<int> m[3];
	
	rep(i,1,3){
		int val = 0;
		while(sz(s[i])){
			pii tmp = *s[i].begin();
			s[i].erase(s[i].begin());
			val += (tmp.fr - tmp.fr / 2) * tmp.sc;
			tmp.fr /= 2;
			if(tmp.fr){
				s[i].insert(tmp);
			}
			m[i].pb(val);
		}
	}
	
	int dec = sum - w;
	
	if(dec <= 0){
		cout<<"0\n";
		return;
	}
	
	int y = sz(m[2])-1;
	rep(x,0,sz(m[1])){
		if(m[1][x] >= dec)
			amin(ans,x+1);
		while(y > 0 && m[1][x] + m[2][y-1] >= dec){
			y--;
		}
		if(y >= 0 && m[1][x] + m[2][y] >= dec)
			amin(ans,(x+1) + 2*(y+1));
	}
	
	rep(y,0,sz(m[2])){
		if(m[2][y] >= dec)
			amin(ans, 2*(y+1));
	}
	
	cout<<ans<<"\n";
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
	cin>>t;
	while(t--) solve();
	return 0;
}