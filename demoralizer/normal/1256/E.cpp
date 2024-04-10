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


int n;
vector<int> diff;

int dp[N];
int choice[N];

int calc(int i){
	if(i == n - 1){
		return 0;
	}
	
	int &ans = dp[i];
	if(ans != -1){
		return ans;
	}
	
	// not pick
	ans = calc(i+1);
	choice[i] = 0;
	
	// pick
	if(i + 3 < n){
		int tmp = diff[i] + calc(i + 3);
		if(tmp > ans){
			ans = tmp;
			choice[i] = 1;
		}
	}
	return ans;
}

void solve(){
	mem1(dp);
	cin >> n;
	vector<pii> a(n);
	rep(i,0,n){
		cin >> a[i].fr;
		a[i].sc = i;
	}
	
	sort(all(a));
	// 1 2 5 12 13 15
	//  1 3 7  1  2
	
	rep(i,1,n){
		diff.pb(a[i].fr - a[i - 1].fr);
	}
	
	int ans = calc(2);
	
	cout << a.back().fr - a.front().fr - ans << " ";
	
	vector<int> final(n);
	
	final[a[0].sc] = final[a[1].sc] = 1;
	int i = 2;
	int cur  = 1;
	while(i != n - 1){
		final[a[i].sc] = cur;
		if(choice[i]){
			cur++;
			final[a[i+1].sc] = cur;
			final[a[i+2].sc] = cur;
			i += 3;
		}
		else{
			i++;
		}
	}
	final[a[n-1].sc] = cur;
	cout << cur << "\n";
	rep(i,0,n){
		cout << final[i] << " ";
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