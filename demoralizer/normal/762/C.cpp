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

int fr[N];
int bk[N];

void solve(){
	string a,b;
	cin>>a>>b;
	int n = sz(a), m = sz(b);
	int x = 0;
	rep(i,0,n){
		if(a[i] == b[x]){
			x++;
			if(x == m){
				cout<<b;
				return;
			}
		}
		fr[i] = x;
	}
	x = 0;
	for(int i=n-1;i >= 0;i--){
		if(a[i] == b[m-1-x]){
			x++;
			if(x==m){
				cout<<b;
				return;
			}
		}
		bk[i] = x;
	}
	int ans = 0;
	int id = -1;
	rep(i,0,n){
		int l = fr[i] + bk[i+1];
		if(l > ans){
			ans = l;
			id = i;
		}
	}
	
	if(fr[n-1] > ans || bk[0] > ans){
		string s;
		if(fr[n-1] > ans){
			string t;
			ans = fr[n-1];
			rep(i,0,ans){
				t.pb(b[i]);
			}
			s = t;
		}
		if(bk[0] > ans){
			string t;
			ans = bk[0];
			rep(i,0,ans){
				t.pb(b[m - ans + i]);
			}
			s = t;
		}
		cout<<s;
		return;
	}
	
	if(id == -1){
		// if(fr[n-1])cout<<b[0];
		// else if(bk[0])cout<<b[m-1];
		// else 
			cout << "-";
		return;
	}
	rep(i,0,fr[id]){
		cout<<b[i];
	}
	rep(i,0,bk[id+1]){
		cout<<b[m - bk[id+1] + i];
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