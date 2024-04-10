#include <bits/stdc++.h>
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

int a[N];
int has[N];

void solve(){
	int w,l;
	cin>>w>>l;
	rep(i,0,N){
		a[i] = INF;
	}
	rep(i,1,w){
		cin>>a[i];
		if(i<=l){
			has[i] = a[i];
		}
	}
	
	rep(i,1,(w+l-1)/l+1){
		int tot = 0;
		for(int j = l*(i+1); j > l*i; j--){
			if(a[j] < has[j-l]){
				has[j] = a[j];
				has[j-l] -= has[j];
				has[j-l-1] += has[j-l];
			}
			else{
				has[j] = has[j-l];
			}
			has[j-l] = 0;
			tot += has[j];
			has[j] = 0;
		}
		for(int j = l*(i+1); j > l*i; j--){
			has[j] = min(tot,a[j]);
			tot -= has[j];
		}
	}
	
	int ans = 0;
	rep(i,w,N){
		ans += has[i];
	}
	cout<<ans;
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