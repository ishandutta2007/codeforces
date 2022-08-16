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


#define LSB(i) ((i) & -(i))

int n,k;
int a[15];
int t[15];

void print_mask(int mask){
	rep(i,0,n){
		cout << (mask >> i & 1);
	}
}

bool check(int mask, int pos){
	if(pos == k){
		return (mask == 0 || (__builtin_ctzll(mask) + ppcll(mask) == n));
	}
	int total = ppcll(a[pos]);
	int big = ppcll(a[pos] & mask);
	int known = ppcll(a[pos] & t[pos]);
	int small = known - big;
	int unknown = total - known;
	int x = a[pos];
	int tmp = (mask | a[pos]);
	bool ans = 1;
	rep(i,0,small){
		tmp ^= LSB(x);
		x ^= LSB(x);
	}
	rep(i,0,unknown+1){
		ans &= check(tmp,pos+1);
		tmp ^= LSB(x);
		x ^= LSB(x);
	}
	// cout << pos << " "; print_mask(mask); cout << " " << ans << "\n";
	return ans;
}

void solve(){
	cin >> n >> k;
	rep(i,0,k){
		int x;
		cin >> x;
		rep(j,0,x){
			int y;
			cin >> y;
			y--;
			a[i] |= (1ll << y);
		}
		t[i + 1] = a[i] | t[i];
	}
	
	if(n == 1 || (ppcll(t[k]) == n && check(0,0))){
		cout << "ACCEPTED\n";
	}
	else{
		cout << "REJECTED\n";
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