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

const int N=2e5+5;

int a[N];
int b[N];

int sm[N];
int bg[N];

void solve(){
	int n;
	cin >> n;
	
	set<int> s;
	rep(i,1,2*n+1){
		s.insert(i);
	}
	rep(i,0,n){
		cin >> a[i];
		s.erase(a[i]);
	}
	
	rep(i,0,n){
		b[i] = *s.begin();
		s.erase(s.begin());
	}
	
	int j = 0;
	rep(i,0,n){
		while(j < n && a[i] > b[j]) j++;
		sm[i] = n - j + i;
	}
	
	j = n - 1;
	for(int i = n - 1; i >= 0; i--){
		while(j >= 0 && a[i] < b[j]) j--;
		bg[i] = j + 1 + (n - 1 - i);
	}
	
	
	multiset<int> ss,sb;
	ss.insert(n + 10);
	sb.insert(n + 10);
	int ans = 0;
	rep(i,0,n){
		sb.insert(bg[i]);
	}
	
	if(*sb.begin() >= n){
		ans++;
	}
	
	rep(i,0,n){
		ss.insert(sm[i]);
		sb.erase(sb.find(bg[i]));
		if(*ss.begin() >= (i + 1) && *sb.begin() >= (n - 1 - i)){
			ans++;
		}
	}
	cout << ans << "\n";
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