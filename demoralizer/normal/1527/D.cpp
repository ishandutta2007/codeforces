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

vector<int> v[N];
int siz[N];
int lvl[N];

int forefather[N];

int tim = 0, st[N], et[N];

void dfs(int z,int p = -1,int ff = 0){
	if(p == -1) lvl[z] = 0;
	else lvl[z] = lvl[p] + 1;
	
	if(lvl[z] == 1) ff = z;
	forefather[z] = ff;
	
	st[z] = tim++;
	
	siz[z] = 1;
	for(int x:v[z]){
		if(x == p) continue;
		dfs(x,z,ff);
		siz[z] += siz[x];
	}
	et[z] = tim;
}

// x is ancestor of y
bool ancestor(int x,int y){
	if(st[y] > st[x] && et[y] <= et[x]){
		return true;
	}
	return false;
}

int calc(int x,int y){
	if(y == 0) swap(x,y);
	if(x == 0){
		return siz[y] * (siz[0] - siz[forefather[y]]);
	}
	return siz[x] * siz[y];
}

void solve(){
	tim = 0;
	int n;
	cin >> n;
	rep(i,0,n){
		v[i].clear();
		siz[i] = 0;
		lvl[i] = 0;
		forefather[i] = 0;
	}
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	dfs(0);
	
	int paths = n * (n - 1) / 2;
	int donthavezero = 0;
	rep(i,1,n){
		if(lvl[i] != 1) continue;
		donthavezero += siz[i] * (siz[i] - 1) / 2;
	}
	cout << donthavezero << " ";
	paths -= donthavezero;
	
	int a = 0, b = 0;
	
	rep(i,1,n){
		if(paths == 0){
			cout << 0 << " ";
			continue;
		}
		if(a == 0) swap(a,b);
		if(ancestor(i,a) || ancestor(i,b)){
			cout << 0 << " ";
			continue;
		}
		if(ancestor(a,i)){
			a = i;
			int wont_work = calc(a,b);
			cout << paths - wont_work << " ";
			paths = wont_work;
		}
		else if(ancestor(b,i)){
			if(forefather[i] == forefather[a]){
				cout << paths << " ";
				paths = 0;
				continue;
			}
			b = i;
			int wont_work = calc(a,b);
			cout << paths - wont_work << " ";
			paths = wont_work;
		}
		else{
			cout << paths << " ";
			paths = 0;
		}
	}
	
	cout << paths;
	
	cout << "\n";
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
	cin>>t;
	while(t--) solve();
	return 0;
}