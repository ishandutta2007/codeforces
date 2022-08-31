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

int dish[N];
int used[N];

pii frnd[N];
int vis[N];

vector<int> v[N];

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,1,n+1){
		cin >> dish[i];
	}
	
	rep(i,0,m){
		int x,y;
		cin>>x>>y;
		frnd[i] = {x,y};
		v[x].pb(i);
		v[y].pb(i);
		dish[x]--;
		dish[y]--;
	}
	
	int cnt = 0;
	
	queue<int> q;
	rep(i,1,n+1){
		if(dish[i] >= 0){
			used[i] = 1; cnt++;
			q.push(i);
		}
	}
	
	vector<int> order;
	
	while(!q.empty()){
		int x = q.front();
		// cout << x << "  |\n";
		q.pop();
		for(int y:v[x]){
			if(vis[y]) continue;
			vis[y] = 1;
			order.pb(y + 1);
			if(!used[frnd[y].fr] && (++dish[frnd[y].fr]) >= 0){
				used[frnd[y].fr] = 1; cnt++;
				q.push(frnd[y].fr);
			}
			if(!used[frnd[y].sc] && (++dish[frnd[y].sc]) >= 0){
				used[frnd[y].sc] = 1; cnt++;
				q.push(frnd[y].sc);
			}
		}
	}
	
	if(cnt < n){
		cout << "DEAD";
		return;
	}
	
	cout << "ALIVE\n";
	while(!order.empty()){
		cout << order.back() << " ";
		order.ppb();
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