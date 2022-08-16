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

const int N=1e5+5;

int b[N];
vector<int> v[62];

void fail(){
	cout << "No";
	exit(0);
}

void solve(){
	int n;
	cin >> n;
	int mx = 0;
	rep(i,0,n){
		cin >> b[i];
		int tmp = b[i];
		int cnt = 0;
		while(tmp){
			cnt++;
			tmp/=2;
		}
		cnt--;
		v[cnt].pb(b[i]);
		amax(mx,cnt);
	}
	
	if(sz(v[mx]) > 1){
		fail();
	}
	
	vector<int> ans;
	
	while(mx >= 0){
		vector<int> tmp;
		int j = 0;
		bool f = 0;
		while(sz(v[mx])){
			if(!f){
				f = 1;
				tmp.pb(v[mx].back());
				v[mx].ppb();
			}
			else{
				if(j == sz(ans)) fail();
				tmp.pb(ans[j]);
				f ^= (ans[j] >> mx & 1);
				j++;
			}
		}
		while(j < sz(ans)){
			tmp.pb(ans[j]);
			j++;
		}
		swap(ans,tmp);
		mx--;
	}
	
	cout << "Yes\n";
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