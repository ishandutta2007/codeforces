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
const int32_t M=1e6+3;
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

struct row{
	int val[11];
	int c;
	row(){
		rep(i,0,11){
			val[i] = 0;
		}
		c = 0;
	}
	row(vector<int> v,int C){
		rep(i,0,11){
			val[i] = v[i];
		}
		c = C;
	}
	row operator*= (int x){
		if(x < 0) x += M;
		rep(i,0,11){
			val[i] = val[i] * x % M;
		}
		c = c * x % M;
		return *this;
	}
	friend row operator* (const int x,const row y){
		return row(y) *= x;
	}
	row operator+= (const row other){
		rep(i,0,11){
			val[i] = (val[i] + other.val[i]) % M;
		}
		c = (c + other.c) % M;
		return *this;
	}
	friend row operator+ (const row x,const row y){
		return row(x) += y;
	}
} r[11];

bool eliminate(){
	rep(i,0,11){
		int j = i;
		while(j < 11 && r[i].val[j] == 0) j++;
		if(j == 11) return false;
		if(j != i){
			swap(r[i],r[j]);
			j = i;
		}
		rep(k,0,11){
			if(i == k) continue;
			int b = r[k].val[j];
			int c = r[i].val[j];
			int mul = b * pw(c) % M;
			mul = M - mul;
			r[k] += mul * r[i];
		}
	}
	return true;
}
int a[11];
int eval_____(int x){
	int k = 1;
	int ans = 0;
	rep(i,0,11){
		ans = (ans + a[i] * k % M) % M;
		k = k * x % M;
	}
	return ans;
}

void solve(){
	rep(i,0,11){
		rep(j,0,11){
			r[i].val[j] = pw(i,j);
		}
		cout << "? " << i << endl;
		cin >> r[i].c;
	}
	
	eliminate();
	rep(i,0,11){
		a[i] = r[i].c * pw(r[i].val[i]);
	}
	
	
	rep(i,0,M){
		if(eval_____(i) == 0){
			cout << "! " << i << endl;
			return;
		}
	}
	cout << "! " << -1 << endl;
}
signed main(){
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