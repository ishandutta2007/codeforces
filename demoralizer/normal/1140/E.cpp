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
const int32_t M=998244353;

const int N=2e5+5;

int a[N];

void solve(){
	int n,k;
	cin >> n >> k;
	rep(i,0,n){
		cin >> a[i];
	}
	
	rep(i,2,n){
		if(a[i] != -1 && a[i] == a[i-2]){
			cout << 0;
			return;
		}
	}
	
	vector<pair<int, pii>> v;
	
	int curs = 0;
	int len = 0;
	
	for(int i = 0; i < n; i += 2){
		if(a[i] == -1){
			len++;
		}
		else{
			if(len){
				v.pb({len,{curs,a[i]}});
				len = 0;
			}
			curs = a[i];
		}
	}
	
	if(len){
		v.pb({len,{curs,0}});
	}
	
	curs = 0;
	len = 0;
	for(int i = 1; i < n; i += 2){
		if(a[i] == -1){
			len++;
		}
		else{
			if(len){
				v.pb({len,{curs,a[i]}});
				len = 0;
			}
			curs = a[i];
		}
	}
	
	if(len){
		v.pb({len,{curs,0}});
	}
	
	int fans = 1;
	
	for(auto x:v){
		int l = x.fr, s = x.sc.fr, e = x.sc.sc;
		if(s == 0 && e == 0){
			int ans = k;
			rep(i,1,l) ans = ans * (k - 1) % M;
			fans = fans * ans % M;
			continue;
		}
		if(s == 0 || e == 0){
			int ans = 1;
			rep(i,0,l) ans = ans * (k - 1) % M;
			fans = fans * ans % M;
			continue;
		}
		if(s == e){
			int nes = k - 1;
			int eqs = 0;
			rep(i,1,l){
				int tmp = nes;
				nes = (nes * (k - 2) % M + eqs * (k - 1) % M) % M;
				eqs = tmp;
			}
			fans = fans * nes % M;
			continue;
		}
		int eqs = 0;
		int eqe = 1;
		int non = (k - 2);
		rep(i,1,l){
			int n_eqs = (eqe + non) % M;
			int n_eqe = (eqs + non) % M;
			int n_non = ((eqs + eqe) % M * (k - 2) % M + non * (k - 3) % M) % M;
			eqs = n_eqs;
			eqe = n_eqe;
			non = n_non;
		}
		fans = fans * ((eqs + non) % M) % M;
	}
	cout << fans;
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