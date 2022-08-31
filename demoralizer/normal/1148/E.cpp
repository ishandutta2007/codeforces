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

pii s[N];
pii t[N];
int diff[N];

void solve(){
	int n;
	cin >> n;
	rep(i,0,n){
		cin >> s[i].fr;
		s[i].sc = i + 1;
	}
	rep(i,0,n){
		cin >> t[i].fr;
		t[i].sc = i + 1;
	}
	sort(s,s+n);
	sort(t,t+n);
	
	queue<int> neg;
	
	rep(i,0,n){
		diff[i] = t[i].fr - s[i].fr;
		if(diff[i] < 0){
			neg.push(i);
		}
	}
	
	int cur = 0;
	rep(i,0,n){
		cur += diff[i];
		if(cur < 0){
			cout << "NO\n";
			return;
		}
	}
	
	if(cur != 0){
		cout << "NO\n";
		return;
	}
	
	cout << "YES\n";
	vector<pair<pii, int>> ans;
	
	rep(i,0,n){
		int x = diff[i];
		while(x > 0){
			int f = neg.front();
			int tmp = min(x,-diff[f]);
			x -= tmp;
			diff[f] += tmp;
			ans.pb({{s[i].sc,s[f].sc},tmp});
			if(diff[f] == 0){
				neg.pop();
			}
		}
	} 
	
	cout << sz(ans) << "\n";
	for(auto x:ans){
		cout << x << "\n";
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