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

vector<int> manacher(vector<int> s){
	int n = sz(s);
	vector<int> d1(n);
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
	return d1;
}

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i,0,n){
		cin >> a[i];
	}
	int j = 1;
	while(j < n && a[j] == a[j-1] + 1){
		j++;
	}
	vector<int> b;
	rep(i,0,n){
		int k = (i + j) % n;
		b.pb(a[k]);
	}
	b.pb(b.front());
	vector<pii> seg;
	seg.pb({b[0],b[0]});
	rep(i,1,n + 1){
		int x = b[i];
		int y = seg.back().sc;
		if((y + 1) % m == x){
			seg.back().sc = x;
		}
		else{
			seg.pb({(y+1)%m,(x+m-1)%m});
			seg.pb({x,x});
		}
	}
	seg.ppb();
	int tmp = sz(seg);
	rep(j,0,2){
		rep(i,0,tmp){
			seg.pb(seg[i]);
		}
	}
	vector<int> wid(sz(seg));
	rep(i,0,sz(seg)){
		wid[i] = (seg[i].sc - seg[i].fr + m) % m + 1;
	}
	
	vector<int> lps = manacher(wid);
	
	vector<int> ans;
	rep(i,tmp,tmp*2){
		int val = (seg[i].fr + seg[i].sc) % m;
		int len = (tmp + 1) / 2;
		if(lps[i] >= len){
			ans.pb(val);
		}
	}
	sort(all(ans));
	uniq(ans);
	cout << sz(ans) << "\n";
	for(int x:ans){
		cout << x << " ";
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