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

int p[N];
int vis[N];

void solve(){
	int n;
	cin>>n;
	int f = 0;
	rep(i,1,n+1){
		cin>>p[i];
		if(p[i] == i) f = i;
	}
	if(f){
		cout<<"YES\n";
		rep(i,1,n+1){
			if(f == i) continue;
			cout<<f<<" "<<i<<"\n";
		}
		return;
	}
	int a = 0, b = 0;
	
	rep(i,1,n+1){
		if(p[p[i]] == i){
			a = i;
			b = p[i];
			break;
		}
	}
	
	if(a){
		vector<pii> e;
		e.pb({a,b});
		vis[a] = vis[b] = 1;
		rep(i,1,n+1){
			if(vis[i]) continue;
			int x = i, cnt = 0;
			do{
				cnt++;
				if(cnt%2) e.pb({a,x});
				else e.pb({b,x});
				vis[x] = 1;
				x = p[x];
			}while(x != i);
			if(cnt%2){
				cout<<"NO";
				return;
			}
		}
		cout<<"YES\n";
		for(pii x:e){
			cout<<x<<"\n";
		}
		return;
	}
	
	cout<<"NO";
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