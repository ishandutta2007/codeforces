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

const int N=2e5+5;

int avail[N];

void solve(){
	int a,b,h,w,n;
	cin>>a>>b>>h>>w>>n;
	vector<int> v(n);
	for(int &x:v)cin>>x;
	sort(all(v));
	reverse(all(v));
	if(n>34){
		n=34;
		v.resize(n);
	}
	
	int tot = 1;
	int cnt = 0;
	vector<int> vals;
	vals.pb(1);
	avail[1] = 1;
	if(h>=a && w>=b){
		cout<<0;
		return;
	}
	swap(a,b);
	if(h>=a && w>=b){
		cout<<0;
		return;
	}
	for(int x:v){
		cnt++;
		tot *= x;
		vector<int> nvals;
		for(int y:vals){
			nvals.pb(x*y);
		}
		for(int y:nvals){
			if(y < N && !avail[y]){
				vals.pb(y);
				avail[y] = 1;
			}
		}
		for(int y:vals){
			if((h*y >= a && w*(tot/y) >= b) || (h*(tot/y) >= a && w*y >= b)){
				cout<<cnt;
				return;
			}
			swap(a,b);
			if((h*y >= a && w*(tot/y) >= b) || (h*(tot/y) >= a && w*y >= b)){
				cout<<cnt;
				return;
			}
		}
	}
	cout<<-1;
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
	while(t--){
		solve();
		cout<<"\n";
		int x = 1;
	}
	return 0;
}