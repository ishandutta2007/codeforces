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

const int N=3e5+5;

#define NCR
#define PRIME	M
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
int fact[N],invfact[N];
void init(){
	int p=PRIME;
	fact[0]=1;
	int i;
	for(i=1;i<N;i++){
		fact[i]=i*fact[i-1]%p;
	}
	i--;
	invfact[i]=pw(fact[i],p-2,p);
	for(i--;i>=0;i--){
		invfact[i]=invfact[i+1]*(i+1)%p;
	}
}
int ncr(int n,int r){
	if(r > n || n < 0 || r < 0)return 0;
	return fact[n]*invfact[r]%PRIME*invfact[n-r]%PRIME;
}

int beg(int n,int r){
	if(n == 0 && r == 0){
		return 1;
	}
	return ncr(n + r - 1, r - 1);
}

int val(vector<vector<int>> c){
	rep(i,0,2){
		rep(j,0,2){
			if(c[i][j] < 0){
				return 0;
			}
		}
	}
	
	int z = 1 + c[1][0];
	int o = c[0][1];
	
	if(z > o + 1 || o > z){
		return 0;
	}
	
	int ans = 1;
	ans = ans * beg(c[1][1],o) % M;
	ans = ans * beg(c[0][0],z) % M;
	return ans;
}

int calc(vector<vector<int>> c, string a){
	int ans = 0;
	int len = 1;
	rep(i,0,2) rep(j,0,2) len += c[i][j];
	if(len < sz(a)){
		swap(c[1][0],c[0][1]);
		swap(c[0][0],c[1][1]);
		return val(c);
	}
	if(len > sz(a)){
		return 0;
	}
	int prev = a[0] - '0';
	rep(i,1,sz(a)){
		int d = a[i] - '0';
		if(d == 1){
			if(prev != -1){
				c[prev][0]--;
			}
			ans = (ans + val(c)) % M;
			if(prev != -1){
				c[prev][0]++;
			}
		}
		if(prev != -1){
			c[prev][d]--;
		}
		prev = d;
	}
	ans += (c[0][0] == 0 && c[0][1] == 0 && c[1][0] == 0 && c[1][1] == 0);
	return ans;
}

void solve(){
	string a,b;
	vector<vector<int>> c(2,vector<int>(2));
	cin >> a >> b;
	rep(i,0,2){
		rep(j,0,2){
			cin >> c[i][j];
		}
	}
	
	if(c[0][0] == 0 && c[1][1] == 0 && c[0][1] == 0 && c[1][1] == 0){
		cout << (a == "1");
		return;
	}
	
	reverse(all(a));
	for(char &c:a){
		if(c == '1'){
			c = '0';
			break;
		}
		else{
			c = '1';
		}
	}
	if(a.back() == '0' && sz(a) > 1) a.ppb();
	reverse(all(a));
	
	int ans = (calc(c,b) + M - calc(c,a)) % M;
	cout << ans;
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