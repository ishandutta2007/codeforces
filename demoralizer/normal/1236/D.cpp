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

// 0 -> right, 1 -> down, 2 -> left, 3 -> up

vector<int> row[N],col[N];

void solve(){
	int a = 1, b = 1;
	int n,m,k;
	cin >> n >> m >> k;
	
	int req = n * m;
	
	rep(i,1,n+1){
		row[i].pb(0);
		row[i].pb(m+1);
	}
	
	rep(i,1,m+1){
		col[i].pb(0);
		col[i].pb(n+1);
	}
	
	rep(i,0,k){
		int x,y;
		cin >> x >> y;
		row[x].pb(y);
		col[y].pb(x);
	}
	
	rep(i,0,N){
		sort(all(row[i]));
		sort(all(col[i]));
	}
	
	int x = 1, y = 0;
	int ans = 0;
	int dir = 0;
	
	while(1){
		if(dir == 0){
			int obs = min((*upper_bound(all(row[x]),y)) - 1,m);
			int dis = obs - y;
			ans += dis;
			if(dis == 0){
				break;
			}
			a = x + 1;
			y = obs;
		}
		else if(dir == 1){
			int obs = min((*upper_bound(all(col[y]),x)) - 1,n);
			int dis = obs - x;
			ans += dis;
			if(dis == 0){
				break;
			}
			m = y - 1;
			x = obs;
		}
		else if(dir == 2){
			auto it = upper_bound(all(row[x]),y);
			it--;
			int obs = max((*it) + 1,b);
			int dis = y - obs;
			ans += dis;
			if(dis == 0){
				break;
			}
			n = x - 1;
			y = obs;
		}
		else{
			auto it = upper_bound(all(col[y]),x);
			it--;
			int obs = max((*it) + 1,a);
			int dis = x - obs;
			ans += dis;
			if(dis == 0){
				break;
			}
			b = y + 1;
			x = obs;
		}
		dir = (dir + 1) % 4;
	}
	
	if(ans + k == req){
		cout << "Yes";
	}
	else{
		cout << "No";
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