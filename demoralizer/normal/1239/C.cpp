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

int t[N];
int ans[N];

void solve(){
	int n,p;
	cin >> n >> p;
	rep(i,0,n){
		cin >> t[i];
	}
	
	// waiting for timer, waiting on seat, waiting in queue, using tank
	
	set<pii> timer;
	rep(i,0,n){
		timer.insert({t[i],i});
	}
	
	set<int> seat, inq;
	
	queue<int> q;
	
	int tank_user = -1, tank_free = INF, time = 0;
	
	while(time < INF){
		// cout << time << endl;
		if(tank_user == -1){
			if(!q.empty()){
				int top = q.front();
				q.pop();
				tank_user = top;
				tank_free = time + p;
				continue;
			}
		}
		
		if(!seat.empty() && inq.upper_bound(*seat.begin()) == inq.begin()){
			int top = *seat.begin();
			seat.erase(seat.begin());
			inq.insert(top);
			q.push(top);
			continue;
		}
		
		int nxt = INF;
		if(!timer.empty()) nxt = timer.begin()->fr;
		
		if(tank_free < nxt && tank_user != -1){
			ans[tank_user] = tank_free;
			inq.erase(tank_user);
			tank_user = -1;
			nxt = tank_free;
		}
		else if(!timer.empty()){
			auto top = *timer.begin();
			timer.erase(timer.begin());
			seat.insert(top.sc);
		}
		else{
			break;
		}
		time = nxt;
	}
	
	rep(i,0,n){
		cout << ans[i] << " ";
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