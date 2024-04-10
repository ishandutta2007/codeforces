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

int c[60];

void solve(){
	int n;
	cin >> n;
	rep(i,0,n){
		cin >> c[i];
	}
	
	if(n == 1){
		cout << 0;
		return;
	}
	
	
	cout << n - (n % 2 == 0) - (c[0] == 1) << "\n";
	
	
	// 1 goes to first
	rep(i,(c[0] == 1),(n - (n % 2 == 0))){
		int pos;
		rep(j,0,n){
			if(c[j] == i+1){
				pos = j;
				break;
			}
		}
		// cout << i+1 << " " <<  pos << "\n";
		cout << i+2 - ((pos == n-1 && i % 2 == 1) || (pos == 0 && i % 2 == 0)) << " ";
		vector<int> segs;
		if(i % 2 == 0){
			if(pos){
				cout << pos << " ";
				segs.pb(pos);
			}
			cout << n - pos - i << " ";
			segs.pb(n-pos-i);
			rep(j,0,i) cout << 1 << " ",segs.pb(1);
		}
		else{
			rep(j,0,i) cout << 1 << " ",segs.pb(1);
			cout << pos + 1 - i << " ";
			segs.pb(pos+1-i);
			if(n - 1 - pos){
				cout << n - 1 - pos << " ";
				segs.pb(n-1-pos);
			}
		}
		cout << "\n";
		
		vector<int> v;
		int cur = n;
		reverse(all(segs));
		for(int x:segs){ //cout <<"seg-> " << x << "\n";
			rep(j,cur-x,cur){
				v.pb(c[j]);
			}
			cur -= x;
		}
		rep(j,0,n){
			c[j] = v[j];
			// cout << c[j] << " ";
		}
		// cout << "|aarry\n";
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