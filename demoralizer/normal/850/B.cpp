#include <bits/stdc++.h>
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

const int N=1e6+5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define SEIVE
int primes[N];
vector<int> pr;
vector<int> pf[N];
void seive(){
	for(int i=2;i<N;i++){
		if(primes[i]==0){
			pr.pb(i);
			for(int j=i;j<N;j+=i){
				primes[j]=1;
				pf[j].pb(i);
			}
		}
		primes[i]^=1;
	}
}

#define int               long long
int n,x,y;
int a[N];
int v[N];
int v1[N];

int calc(int k){
	int ans=0;
	rep(i,0,n){
		ans += min(x,y*(((a[i]+k-1)/k)*k-a[i]));
	}
	return ans;
}

void solve(){
	cin>>n>>x>>y;
	rep(i,0,n){
		cin>>a[i];
	}
	if(x<=y){
		rep(i,0,n){
			for(int x:pf[a[i]]){
				v[x]++;
			}
		}
		int mx=0;
		for(int y:pr){
			amax(mx,v[y]);
		}
		cout<<x*(n-mx);
		return;
	}
	else if(x<2*y){
		rep(i,0,n){
			for(int x:pf[a[i]]){
				v[x]++;
			}
			for(int x:pf[a[i]+1]){
				v1[x]++;
			}
		}
		int mn=INF;
		for(int z:pr){
			amin(mn,v1[z]*y + (n-v[z]-v1[z])*x);
		}
		cout<<mn;
		return;
	}
	
	auto rnd=uniform_int_distribution<int>(0,n-1);
	
	set<int> prs;
	rep(i,0,15){
		int k=rnd(rng);
		for(int x:pf[a[k]]){
			prs.insert(x);
		}
	}
	
	int ans=INF;
	prs.insert(2);
	
	for(int k:prs){
		amin(ans,calc(k));
	}
	cout<<ans;
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