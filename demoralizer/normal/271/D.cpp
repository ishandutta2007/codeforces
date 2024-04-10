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

const int N=1600;

int b1,b2;
int pb1[N];
int pb2[N];
struct hsh
{
	int n;
	vector<int> v1;
	vector<int> v2;
	hsh(string &s){
		n = sz(s);
		v1.resize(n + 1);
		v2.resize(n + 1);
		rep(i,1,n+1){
			v1[i] = (v1[i - 1] + s[i - 1] * 1ll * pb1[i - 1]) % M;
			v2[i] = (v2[i - 1] + s[i - 1] * 1ll * pb2[i - 1]) % MM;
		}
	}
	pii sub(int l,int r){
		int h1 = (v1[r + 1] + M - v1[l]) * 1ll * pb1[n - r] % M;
		int h2 = (v2[r + 1] + MM - v2[l]) * 1ll * pb2[n - r] % MM;
		return {h1,h2};
	}
};

void solve(){
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	auto dist=uniform_int_distribution<int>(1000,5000);
	b1 = dist(rng);
	b2 = dist(rng);
	pb1[0] = pb2[0] = 1;
	rep(i,1,N){
		pb1[i] = pb1[i-1] * 1ll * b1 % M;
		pb2[i] = pb2[i-1] * 1ll * b2 % MM;
	}
	
	int k;
	string s,t;
	cin >> s >> t >> k;
	int n = sz(s);
	int val[200] = {0};
	rep(i,0,26){
		val['a' + i] = !(t[i] - '0');
	}
	
	hsh h = s;
	int pf[N];
	pf[0] = 0;
	rep(i,1,n+1){
		pf[i] = pf[i - 1] + val[s[i - 1]];
	}
	
	set<pii> st;
	rep(i,0,n){
		rep(j,i,n){
			if(pf[j + 1] - pf[i] <= k){
				st.insert(h.sub(i,j));
			}
		}
	}
	cout << sz(st);
	
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