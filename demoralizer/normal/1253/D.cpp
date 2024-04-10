#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

#define DSU
#define MAXDSUSIZE N 
int parent[MAXDSUSIZE],size[MAXDSUSIZE],mx[MAXDSUSIZE];
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
	if(size[parent_a]>=size[parent_b])
	{
		size[parent_a]+=size[parent_b];
		parent[parent_b]=parent_a;
		amax(mx[parent_a],mx[parent_b]);
	}
	else
	{
		size[parent_b]+=size[parent_a];
		parent[parent_a]=parent_b;
		amax(mx[parent_b],mx[parent_a]);
	}
	return;
}
void cleardsu(int n){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		size[i]=1;
		mx[i]=i;
	}
}

void solve(){
	int n,m;
	cin>>n>>m;
	cleardsu(n+1);
	rep(i,0,m){
		int x,y;
		cin>>x>>y;
		unionNodes(x,y);
	}
	int ans=0;
	rep(i,1,n+1){
		int y=i+1;
		while(mx[findParent(i)]>=y){
			if(findParent(y)!=findParent(i)){
				ans++;
				unionNodes(i,y);
			}
			y++;
		}
		i=mx[findParent(i)];
	}
	cout<<ans;
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