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

int chint(char c){
	return c-'0';
}

vector<int> open[N];
vector<int> clos[N];
int ans[N];

void solve(){
	int n,m,t;
	cin>>n>>m>>t;
	
	rep(i,0,n){
		string s;
		cin>>s;
		int h = chint(s[0])*10 + chint(s[1]);
		int m = chint(s[3])*10 + chint(s[4]);
		int sec = chint(s[6])*10 + chint(s[7]);
		
		int tim = 3600*h + 60*m + sec;
		open[tim].pb(i);
		
	}
	
	map<int, int> opened;
	
	int r = 0;
	int cur = 0;
	
	int latest = 0;
	
	int mx = 0;
	
	rep(i,0,86401){
		for(int x:open[i]){
			if(cur < m){
				ans[x] = ++r;
				cur++;
				opened[r]++;
				clos[i+t-1].pb(r);
			}
			else{
				ans[x] = r;
				clos[i+t-1].pb(r);
				opened[r]++;
			}
		}
		
		amax(mx,cur);
		
		for(int x:clos[i]){
			opened[x]--;
			if(!opened[x]){
				opened.erase(x);
				cur--;
			}
		}
	}
	
	if(mx<m){
		cout<<"No solution";
	}
	else{
		cout<<r<<"\n";
		rep(i,0,n){
			cout<<ans[i]<<"\n";
		}
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