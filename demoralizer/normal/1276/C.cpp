#include "bits/stdc++.h"
using namespace std;
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

const int N=4e5+5;
const int b = 640;

int a[N];
int freq[N];
int inv[N];

void solve(){
	int n;
	cin>>n;
	int cnt = 0;
	map<int, int> cm;
	set<int> c;
	rep(i,0,n){
		cin>>a[i];
		c.insert(a[i]);
	}
	for(int x:c){
		inv[cnt]=x;
		cm[x] = cnt++;
	}
	rep(i,0,n){
		freq[cm[a[i]]]++;
	}
	
	pii ans = {0,0};
	
	rep(h,1,b){
		int tmp = 0;
		rep(i,0,N){
			tmp += min(freq[i],h);
		}
		if(tmp < h * h) continue;
		tmp = tmp / h;
		if(tmp * h > ans.fr * ans.sc){
			ans = {h,tmp};
		}
	}
	
	cout<<ans.fr*ans.sc<<"\n";
	cout<<ans.fr<<" "<<ans.sc<<"\n";
	vector<pii> v;
	int h=ans.fr;
	rep(i,0,N){
		if(freq[i])
			v.pb({min(freq[i],h),inv[i]});
	}
	sort(all(v));
	reverse(all(v));
	vector<int> z;
	for(auto x:v){
		rep(i,0,x.fr) z.pb(x.sc);
	}
	vector<vector<int>> pr(h,vector<int>(ans.sc));
	int id=0;
	rep(j,0,ans.sc){
		rep(i,0,h){
			pr[i][j] = z[id++];
		}
	}
	rep(i,0,h){
		rep(j,0,ans.sc){
			cout<<pr[i][(j-i+ans.sc)%ans.sc]<<" ";
		}
		cout<<"\n";
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