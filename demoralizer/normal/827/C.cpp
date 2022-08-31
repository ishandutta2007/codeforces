#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fbo               find_by_order
#define ook               order_of_key
template<typename T>
using oset = __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
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

int v[100];
oset<int> s[4][11][11];

void solve(){
	v['A'] = 0;
	v['T'] = 1;
	v['G'] = 2;
	v['C'] = 3;
	
	string t;
	cin>>t;
	rep(i,0,sz(t)){
		rep(j,1,11){
			s[v[t[i]]][j][i%j].insert(i);
		}
	}
	
	int q;
	cin>>q;
	rep(z,0,q){
		int type;
		cin>>type;
		if(type==1){
			int x;string c;
			cin>>x>>c;
			x--;
			rep(j,1,11){
				s[v[t[x]]][j][x%j].erase(x);
			}
			t[x] = c[0];
			rep(j,1,11){
				s[v[t[x]]][j][x%j].insert(x);
			}
		}
		else{
			int l,r;string e;
			cin>>l>>r>>e;
			l--;r--;
			int j = sz(e);
			int ans = 0;
			rep(i,0,j){
				auto &x = s[v[e[i]]][j][(l+i)%j];
				ans += x.ook(r+1) - x.ook(l);
			}
			cout<<ans<<"\n";
		}
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