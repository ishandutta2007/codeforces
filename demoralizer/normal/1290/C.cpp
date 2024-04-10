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

const int N=3e5+5;
const int K=(1<<20);

int parent[N+K];
int siz[N+K];
int elems[N+K];
int must[N+K];
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
	elems[parent_b]+=elems[parent_a];
	must[parent_b]|=must[parent_a];
	parent[parent_a]=parent_b;
	return;
}
void cleardsu(int n){
	for(int i=1;i<=n;i++){
		parent[i] = i;
		siz[i] = 1;
		elems[i] = 1;
		parent[i+K] = i + K;
		siz[i+K] = 1;
	}
}

vector<int> v[N];

int answer(int x){
	x = findParent(x);
	int xK = findParent(x ^ K);
	if(must[x]){
		assert(!must[xK]);
		return elems[x];
	}
	if(must[xK]){
		assert(!must[x]);
		return elems[xK];
	}
	return min(elems[x],elems[xK]);
}

void setmust(int x){
	x = findParent(x);
	must[x] = 1;
}

void solve(){
	cleardsu(N-1);
	int n,k;
	string s;
	cin >> n >> k >> s;
	
	rep(i,1,k+1){
		int c;
		cin >> c;
		while(c--){
			int x;
			cin >> x;
			v[x].pb(i);
		}
	}
	
	int ans = 0;
	
	rep(i,0,n){
		int z = i + 1;
		if(sz(v[z])){
			char c = s[i];
			if(c == '0'){
				if(sz(v[z]) == 1){
					int x = v[z][0];
					ans -= answer(x);
					setmust(x);
					ans += answer(x);
				}
				else{
					int x = v[z][0], y = v[z][1];
					if(findParent(x) != findParent(y ^ K)){
						ans -= answer(x);
						ans -= answer(y);
						unionNodes(x,y ^ K);
						unionNodes(x ^ K,y);
						ans += answer(x);
					}
				}
			}
			else{
				if(sz(v[z]) == 1){
					int x = v[z][0];
					ans -= answer(x);
					setmust(x^K);
					ans += answer(x);
				}
				else{
					int x = v[z][0], y = v[z][1];
					if(findParent(x) != findParent(y)){
						ans -= answer(x);
						ans -= answer(y);
						unionNodes(x,y);
						unionNodes(x ^ K,y ^ K);
						ans += answer(x);
					}
				}
			}
		}
		cout << ans << "\n";
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