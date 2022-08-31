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

const int N=3e5+5;

int a[N];
array<int,20> span[20], spid[N];

void com(array<int,20> &a, array<int,20> &b){
	rep(i,0,20){
		amin(a[i],b[i]);
	}
}

void solve(){
	int n,q;
	cin>>n>>q;
	rep(i,1,n+1){
		cin >> a[i];
		rep(j,0,20){
			spid[i][j] = n+5;
		}
	}
	rep(i,0,20){
		rep(j,0,20){
			span[i][j] = n+5;
		}
	}
	for(int i = n; i > 0; i--){
		rep(j,0,20){
			if(a[i]>>j&1){
				com(spid[i],span[j]);
				spid[i][j] = i;
			}
		}
		rep(j,0,20){
			if(a[i]>>j&1){
				com(span[j],spid[i]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		auto z = spid[x];
		bool found = 0;
		rep(j,0,20){
			if(a[y]>>j&1){
				if(z[j] <= y) found = 1;
			}
		}
		cout << (found?"Shi":"Fou") <<"\n";
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