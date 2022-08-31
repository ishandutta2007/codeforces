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

const int N=1e5+5;

bool cap[N],cant[N];
vector<int> v[N];

void dfs(int z){
	if(cant[z]){
		cout<<"No";
		exit(0);
	}
	if(cap[z]) return;
	cap[z]=1;
	for(int x:v[z]){
		dfs(x);
	}
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> last,cur;
	rep(kk,0,n){
		int l;
		cin>>l;
		if(!kk){
			cur.resize(l);
			for(int &x:cur) cin>>x;
		}
		else{
			swap(last,cur);
			cur.resize(l);
			for(int &x:cur) cin>>x;
			int L=min(sz(last),l);
			rep(i,0,L){
				if(last[i] != cur[i]){
					if(last[i] > cur[i]){
						cant[cur[i]] = 1;
						if(!cap[last[i]]){
							dfs(last[i]);
						}
						if(cap[cur[i]]){
							cout<<"No";
							return;
						}
					}
					else{
						if(cap[cur[i]]){
							dfs(last[i]);
						}
						v[cur[i]].pb(last[i]);
					}
					break;
				}
				if(i+1==L){
					if(l<sz(last)){
						cout<<"No";
						return;
					}
				}
			}
		}
	}
	vector<int> ans;
	rep(i,1,m+1){
		if(cap[i])ans.pb(i);
	}
	cout<<"Yes\n"<<sz(ans)<<"\n";
	for(int x:ans){
		cout<<x<<" ";
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