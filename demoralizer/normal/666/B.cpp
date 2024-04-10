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
template<typename T>T amax(T &a,T b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=3005;

vector<int> v[N];
bool vis[N];
int dis[N][N];

struct mset
{
	set<pii> s;
	mset(){
		s.insert({-INF,0});
		s.insert({-INF,0});
		s.insert({-INF,0});
	}
	void add(pii x){
		s.insert(x);
		if(sz(s) > 3){
			s.erase(s.begin());
		}
	}
	 set<pii>& operator() (){
		return s;
	}
}from[N],to[N];

void bfs(int r){
	mem0(vis);
	queue<pii> q;
	q.push({r,0});
	while(sz(q)){
		int z=q.front().fr;
		int d=q.front().sc;
		q.pop();
		if(vis[z])continue;
		vis[z]=1;
		if(z!=r)from[r].add({d,z});
		if(z!=r)to[z].add({d,r});
		dis[r][z]=d;
		for(int x:v[z]){
			q.push({x,d+1});
		}
	}
}

struct cont{
	int a,b,c,d;
	void print(){
		cout<<a<<" "<<b<<" "<<c<<" "<<d;
	}
}ans;

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,m){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
	}
	
	rep(i,1,n+1){
		bfs(i);
	}
	
	int val=0;
	
	rep(i,1,n+1){
		rep(j,1,n+1){
			if(!dis[i][j])continue;
			auto it1=to[i]().rbegin();
			auto it2=from[j]().rbegin();
			if(it1->sc == j)it1++;
			if(it2->sc == i)it2++;
			
			if(it1->sc != it2->sc){
				int tmp=it1->fr + it2->fr + dis[i][j];
				if(tmp > val){
					val = tmp;
					ans={it1->sc,i,j,it2->sc};
				}
			}
			else{
				auto tmpit=it1;
				it1++;
				if(it1->sc == j)it1++;
				int tmp=it1->fr + it2->fr + dis[i][j];
				if(tmp > val){
					val = tmp;
					ans={it1->sc,i,j,it2->sc};
				}
				it1=tmpit;
				it2++;
				if(it2->sc == i)it2++;
				tmp=it1->fr + it2->fr + dis[i][j];
				if(tmp > val){
					val = tmp;
					ans={it1->sc,i,j,it2->sc};
				}
			}
		}
	}
	ans.print();
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}