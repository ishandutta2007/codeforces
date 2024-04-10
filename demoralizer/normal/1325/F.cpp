#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T>pair<T,T> operator+=(pair<T,T> &a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-=(pair<T,T> &a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T>pair<T,T> operator+(pair<T,T> a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-(pair<T,T> a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const int N=0;

int sqn;
set<int> ind;

vector<int> v[100005];
int dep[100005];
int vis[100005];
vector<int> stk,pr;
int dfs(int z,int d){
	stk.pb(z);
	dep[z]=d;
	vis[z]=1;
	int sl=M;
	for(int x:v[z]){
		if(vis[x]){
			if(dep[z]-dep[x]+1>=sqn){
				cout<<"2\n";
				while(stk.back()!=x){
					pr.pb(stk.back());
					stk.ppb();
				}
				pr.pb(x);
				cout<<sz(pr)<<"\n";
				for(int k:pr){
					cout<<k<<" ";
				}
				exit(0);
			}
			continue;
		}
		amin(sl,dfs(x,d+1));
	}
	stk.ppb();
	if(sl-d+1>=sqn){
		ind.insert(z);
		sl=d;
	}
	if(sl==M)sl=d;
	// if(z<75)cout<<z<<" "<<d<<" "<<sl<<"\n";
	return sl;
}

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,m){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	while(sqn*sqn<n)sqn++;
	dfs(1,0);
	cout<<"1\n";
	rep(i,0,sqn){
		cout<<*ind.begin()<<" ";
		ind.erase(ind.begin());
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// freopen("input.txt", "r", stdin);
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