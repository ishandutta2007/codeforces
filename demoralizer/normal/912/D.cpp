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

const int N=0;

set<pii> vis;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int n,m,r,k;
bool check(int x,int y){
	if(x<1) return 0;
	if(y<1) return 0;
	if(x>n) return 0;
	if(y>m) return 0;
	return 1;
}

int get(int x,int y){
	int a = min(n-r+1,x) - max(0ll,x-r);
	int b = min(m-r+1,y) - max(0ll,y-r);
	return a*b;
}
void solve(){
	cin>>n>>m>>r>>k;
	if(n<m)swap(n,m);
	priority_queue<pair<int, pii>> q;
	int x=(n+1)/2,y=(m+1)/2;
	q.push({get(x,y),{x,y}});
	vis.insert({x,y});
	double ans = 0;
	rep(i,0,k){
		int x = q.top().sc.fr;
		int y = q.top().sc.sc;
		ans += q.top().fr;
		q.pop();
		rep(j,0,4){
			if(check(x+dx[j],y+dy[j]) && !vis.count({x+dx[j],y+dy[j]})){
				vis.insert({x+dx[j],y+dy[j]});
				q.push({get(x+dx[j],y+dy[j]),{x+dx[j],y+dy[j]}});
			}
		}
	}
	ans /= (n-r+1)*(m-r+1);
	cout<<setprecision(9);
	cout<<fixed;
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