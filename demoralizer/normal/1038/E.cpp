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

const int N=6;

int val[N];
int parent[N],siz[N];
int findParent(int i)
{
	if(parent[parent[i]]!=parent[i])
		parent[i]=findParent(parent[i]);
	return parent[i];
}
void unionNodes(int a,int b)
{
	int parent_a=findParent(a),parent_b=findParent(b);
	if(parent_a==parent_b)
		return;
	if(siz[parent_a]>=siz[parent_b]){
		swap(parent_a,parent_b);
	}
	siz[parent_b]+=siz[parent_a];
	val[parent_b]+=val[parent_a];
	parent[parent_a]=parent_b;
	return;
}
void cleardsu(int n){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		siz[i]=1;
		val[i]=0;
	}
}

int deg[5];

vector<int> wt[5][5];
int sum[5][5];

void solve(){
	cleardsu(5);
	int n;
	cin >> n;
	rep(i,0,n){
		int a,b,c;
		cin >> a >> b >> c;
		val[findParent(a)] += b;
		wt[a][c].pb(b);
		if(a == c){
			continue;
		}
		wt[c][a].pb(b);
		unionNodes(a,c);
		deg[a]++;
		deg[c]++;
	}
	
	rep(i,1,5){
		rep(j,1,5){
			sort(all(wt[i][j]));
			for(int x:wt[i][j]){
				sum[i][j] += x;
			}
		}
	}
	
	bool odd = 1;
	int ans = -INF;
	set<int> s;
	rep(i,1,5){
		if(deg[i] % 2 == 0){
			odd = 0;
		}
		amax(ans,val[findParent(i)]);
		s.insert(findParent(i));
	}
	
	if(sz(s) == 1 && odd){
		int tmp = ans;
		ans = 0;
		// remove 1 edge
		rep(i,1,5){
			rep(j,i+1,5){
				if(sz(wt[i][j]) == 0) continue;
				if(sz(wt[i][j]) > 1){
					amax(ans,tmp - wt[i][j][0]);
					continue;
				}
				cleardsu(5);
				rep(x,1,5){
					val[x] = sum[x][x];
				}
				rep(x,1,5){
					rep(y,x+1,5){
						if((x == i && y == j) || sz(wt[x][y]) == 0){
							continue;
						}
						unionNodes(x,y);
						val[findParent(x)] += sum[x][y];
					}
				}
				int res = -INF;
				rep(x,1,5){
					amax(ans,val[findParent(x)]);
				}
			}
		}
	}
	
	cout << ans;
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