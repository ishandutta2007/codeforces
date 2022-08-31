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

int manacher(vector<pii> s){
	int n = sz(s);
	if(n == 0) return 0;
	vector<int> d1(n),d2(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			k++;
		}
		d1[i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
			k++;
		}
		d2[i] = k--;
		if (i + k > r) {
			l = i - k - 1;
			r = i + k ;
		}
	}
	int ans = 0;
	for(int x:d1){
		ans += x;
	}
	for(int x:d2){
		ans += x;
	}
	return ans;
}

int p[30];
int q[30];
int char_to_mask(char c){
	return (1 << (c - 'a'));
}

void solve(){
	int n,m;
	cin >> n >> m;
	string s[n];
	rep(i,0,n){
		cin >> s[i];
	}
	int ans = 0;
	rep(i,0,m){
		vector<int> mask(n);
		vector<pii> hash(n);
		rep(j,i,m){
			rep(k,0,n){
				mask[k] ^= char_to_mask(s[k][j]);
				int x = s[k][j] - 'a';
				hash[k].fr = (hash[k].fr + p[x]) % M;
				hash[k].sc = (hash[k].sc + q[x]) % M;
			}
			
			vector<pii> hashes;
			rep(k,0,n){
				if(ppc(mask[k]) > 1){
					ans += manacher(hashes);
					hashes.clear();
				}
				else{
					hashes.pb(hash[k]);
				}
			}
			ans += manacher(hashes);
		}
	}
	cout << ans;
}

void prc(){
	p[0] = 1;
	q[0] = 1;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	auto dist=uniform_int_distribution<int>(300,3000);
	p[1] = dist(rng);
	q[1] = dist(rng);
	rep(i,2,28){
		p[i] = p[i - 1] * p[1] % M;
		q[i] = q[i - 1] * q[1] % M;
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
	prc();
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}