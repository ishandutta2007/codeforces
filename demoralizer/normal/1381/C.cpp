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

const int N=1e5+5;

int b[N];
vector<int> v[N];

void solve(){
	int n,x,y;
	cin>>n>>x>>y;
	
	set<int> s;
	
	rep(i,1,n+2){
		s.insert(i);
		v[i].clear();
	}
	
	rep(i,0,n){
		cin>>b[i];
		v[b[i]].pb(i);
		s.erase(b[i]);
	}
	
	vector<int> a(n);
	
	int rem = *s.begin();
	
	set<pii , greater<pii>> z;
	
	rep(i,1,n+2){
		if(sz(v[i])){
			z.insert({sz(v[i]),i});
		}
	}
	
	rep(kkk,0,x){
		auto big = *z.begin();
		z.erase(z.begin());
		
		a[v[big.sc].back()] = big.sc;
		v[big.sc].ppb();
		
		if(sz(v[big.sc])) z.insert({sz(v[big.sc]),big.sc});
		
	}
	
	y -= x;
	
	while(y > 0){
		if(y == 3 && sz(z) > 2){
			int p,q,r;
			p = z.begin()->sc;
			z.erase(z.begin());
			q = z.begin()->sc;
			z.erase(z.begin());
			r = z.begin()->sc;
			z.erase(z.begin());
			
			a[v[p].back()] = q;
			a[v[q].back()] = r;
			a[v[r].back()] = p;
			
			y -= 3;
			break;
			
		}
		if(sz(z) < 2){
			cout << "NO\n";
			return;
		}
		if(y == 1){
			int p,q;
			p = z.begin()->sc;
			z.erase(z.begin());
			q = z.begin()->sc;
			z.erase(z.begin());
			
			a[v[p].back()] = q;
			y--;
			break;
		}
		else{
			int p,q;
			p = z.begin()->sc;
			z.erase(z.begin());
			q = z.begin()->sc;
			z.erase(z.begin());
			
			a[v[p].back()] = q;
			a[v[q].back()] = p;
			
			v[p].ppb();
			v[q].ppb();
			
			if(sz(v[p])) z.insert({sz(v[p]),p});
			if(sz(v[q])) z.insert({sz(v[q]),q});
			y -= 2;
		}
	}
	
	cout<<"YES\n";
	rep(i,0,n){
		if(!a[i]) a[i] = rem;
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	
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