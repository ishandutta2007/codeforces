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

const int N=4e5+5;

int parent[N],siz[N],val[N];
int findParent(int i)
{
	if(parent[parent[i]]!=parent[i]){
		int p = parent[i];
		parent[i]=findParent(parent[i]);
		val[i] ^= val[p];
	}
	return parent[i];
}
void unionNodes(int a,int b,int xr)
{
	int parent_a=findParent(a),parent_b=findParent(b);
	if(parent_a==parent_b)
		return;
	if(siz[parent_a]>=siz[parent_b]){
		swap(parent_a,parent_b);
	}
	siz[parent_b]+=siz[parent_a];
	parent[parent_a]=parent_b;
	val[parent_a] = val[a] ^ xr ^ val[b];
	return;
}
void cleardsu(int n){
	for(int i=0;i<n;i++){
		parent[i]=i;
		siz[i]=1;
	}
}

int last = 0;
int cnt = 0;
map<int, int> id;

void solve(){
	int ans;
	int type,l,r;
	cin >> type >> l >> r;
	l ^= last;
	r ^= last;
	if(l > r) swap(l,r);
	l--;
	if(!id.count(l)){
		id[l] = cnt++;
	}
	if(!id.count(r)){
		id[r] = cnt++;
	}
	l = id[l];
	r = id[r];
	if(type == 1){
		int x;
		cin >> x;
		x ^= last;
		unionNodes(l,r,x);
	}
	else{
		if(findParent(l) != findParent(r)){
			ans = -1;
		}
		else{
			ans = val[l] ^ val[r];
		}
		cout << ans << "\n";
		last = abs(ans);
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
	cleardsu(N);
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}