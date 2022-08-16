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

const int N=1e5+20;

#define LSB(i) ((i) & -(i))
const int maxn=N;
struct fenwick{
	int A[maxn];
	int query(int i){
		int sum = 0;
		while (i > 0) 
			sum += A[i], i -= LSB(i);
		return sum;
	}
	void update(int i, int k){
		if(i<1)return;
		while (i < maxn) 
			A[i] += k, i += LSB(i);
	}
	void rupd(int l,int r,int v){
		update(l,v);
		update(r+1,-v);
	}
}fenw;

void clear_fenwick(int n){
	rep(i,1,n+1){
		fenw.update(i,-fenw.query(i));
	}
}

int ans(string s,string t){
	map<char, vector<int>> v;
	int n = sz(t);
	clear_fenwick(n);
	rep(i,0,n){
		v[t[i]].pb(i);
	}
	int r = 0;
	rep(j,0,n){
		int i = n - 1 - j;
		char c = s[i];
		int id = v[c].back();
		v[c].ppb();
		int gone = fenw.query(id+1);
		r += i - id + gone;
		fenw.update(id+1,1);
	}
	return r;
}

void solve(){
	string s;
	cin >> s;
	vector<int> cnt(200);
	for(char c:s){
		cnt[c]++;
	}
	vector<char> v = {'A','N','T','O'};
	sort(all(v));
	
	int best = -1;
	string f;
	
	do{
		string t;
		for(char x:v){
			rep(i,0,cnt[x]){
				t.pb(x);
			}
		}
		// cout << t << "\n";
		int tmp = ans(s,t);
		if(tmp > best){
			best = tmp;
			f = t;
		}
	}while(next_permutation(all(v)));
	cout << f << "\n";
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