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

const int N=0;

int pw(int a,int p=M-2,int MOD=M){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return result;
}

void solve(){
	string s;
	cin >> s;
	
	int n = sz(s);
	
	vector<int> hash(n+1);
	vector<int> gash(n+1);
	hash[0] = 0;
	gash[0] = 0;
	rep(i,1,n+1){
		hash[i] = (hash[i - 1] * 10 % M + (s[i-1] - '0')) % M;
		gash[i] = (gash[i - 1] * 10 % MM + (s[i-1] - '0')) % MM;
	}
	
	auto validate = [&](int l,int r){
		if(s[l - 1] == '0' && r > l){
			return false;
		}
		return true;
	};
	
	auto subhash = [&](int l,int r){
		// 10 ^ (n - r)
		int tmp = (hash[r] - hash[l-1] * pw(10,r - l + 1) % M + M) % M;
		int gmp = (gash[r] - gash[l-1] * pw(10,r - l + 1,MM) % MM + MM) % MM;
		// tmp = tmp * pw(10,r) % M;
		return pii{tmp,gmp};
	};
	
	auto print = [&](int l,int r){
		rep(i,l-1,r){
			cout << s[i];
		}
	};
	
	auto add_pairs = [&](pii a,pii b){
		a.fr += b.fr;
		a.sc += b.sc;
		a.fr %= M;
		a.sc %= MM;
		return a;
	};
	
	rep(w,1,n+1){
		int c = w;
		int a = w;
		int b = n - 2 * w;
		if(b > a || b <= 0) continue;
		// assuming no carry
		// 1 to w
		// w + 1 to w + b
		// w + b + 1 to 2 * w + b = n
		
		// 1...w,w+1...w+b,w+b+1...n
		
		if(validate(1,a) && validate(a+1,a+b) && validate(a+b+1,n))
		if(add_pairs(subhash(1,a), subhash(a+1,a+b)) == subhash(a+b+1,n)){
			print(1,a);
			cout << "+";
			print(a+1,a+b);
			cout << "=";
			print(a+b+1,n);
			return;
		}
		swap(a,b);
		if(validate(1,a) && validate(a+1,a+b) && validate(a+b+1,n))
		if(add_pairs(subhash(1,a), subhash(a+1,a+b)) == subhash(a+b+1,n)){
			print(1,a);
			cout << "+";
			print(a+1,a+b);
			cout << "=";
			print(a+b+1,n);
			return;
		}
	}
	
	rep(w,1,n+1){
		int c = w;
		int a = w - 1;
		int b = n - 2 * w + 1;
		if(b > a || b <= 0 || a <= 0) continue;
		// assuming no carry
		// 1 to w
		// w + 1 to w + b
		// w + b + 1 to 2 * w + b = n
		
		// 1...w,w+1...w+b,w+b+1...n
		
		if(validate(1,a) && validate(a+1,a+b) && validate(a+b+1,n))
		if(add_pairs(subhash(1,a), subhash(a+1,a+b)) == subhash(a+b+1,n)){
			print(1,a);
			cout << "+";
			print(a+1,a+b);
			cout << "=";
			print(a+b+1,n);
			return;
		}
		swap(a,b);
		if(validate(1,a) && validate(a+1,a+b) && validate(a+b+1,n))
		if(add_pairs(subhash(1,a), subhash(a+1,a+b)) == subhash(a+b+1,n)){
			print(1,a);
			cout << "+";
			print(a+1,a+b);
			cout << "=";
			print(a+b+1,n);
			return;
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