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

vector<vector<int>> v;

pii dfs(int z,int p = 0){
	pii ans = {0,z};
	for(int x:v[z]){
		if(x == p) continue;
		amax(ans, dfs(x,z));
	}
	ans.fr++;
	return ans;
}

int target;
vector<int> path;
bool dfs2(int z,int p = 0){
	path.pb(z);
	if(z == target){
		return true;
	}
	for(int x:v[z]){
		if(x == p) continue;
		if(dfs2(x,z)){
			return true;
		}
	}
	path.ppb();
	return false;
}

vector<int> answers;
bool invalid;
int cnt3;
int cnt1;
int convict;
int verify(int z, int p = 0){
	vector<int> q;
	for(int x:v[z]){
		if(x == p) continue;
		q.pb(verify(x,z));
	}
	if(sz(q) == 0) return 1;
	if(sz(q) == 1){
		cnt1++;
		convict = z;
		if(q[0] == 1){
			return 2;
		}
		else{
			invalid = true;
			return -1;
		}
	}
	if(sz(q) == 3){
		cnt3++;
		convict = z;
		sort(all(q));
		if(q[0] == q[2] - 1 && q[1] == q[2] - 1){
			return q[2] + 1;
		}
		else{
			invalid = true;
			return -1;
		}
	}
	if(sz(q) != 2 || q[0] != q[1]){
		invalid = true;
		return -1;
	}
	return q[0] + 1;
}

void solve(){
	int n;
	cin >> n;
	v.resize(N);
	rep(i,0,(1<<n)-3){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	if(n == 2){
		cout << "2\n1 2";
		return;
	}
	
	int a = dfs(1).sc;
	int b = dfs(a).sc;
	
	target = b;
	dfs2(a);
	
	vector<int> roots;
	roots.pb(path[sz(path) / 2]);
	roots.pb(path[(sz(path) - 1) / 2]);
	uniq(roots);
	
	
	for(int r:roots){
		// r is a root
		cnt1 = cnt3 = 0;
		invalid = 0;
		verify(r);
		if(cnt1 + cnt3 == 1 && !invalid){
			answers.pb(convict);
		}
	}
	
	
	cout << sz(answers) << "\n";
	sort(all(answers));
	for(int x:answers){
		cout << x << " ";
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