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

set<int> id[2];
int ans[N];

void solve(){
	
	rep(i,0,2) id[i].clear();
	int n;
	cin>>n;
	string s;
	cin>>s;
	rep(i,0,n){
		id[s[i]-'0'].insert(i);
	}
	
	int num = 1;
	
	while(!id[0].empty() && !id[1].empty()){
		int z; // z is first, !z is 2nd
		if(*id[0].begin() < *id[1].begin()){
			z = 0;
		}
		else{
			z = 1;
		}
		int cur = -1;
		
		while(1){
			if(id[z].lower_bound(cur) == id[z].end())
				break;
			int tmp = *id[z].lower_bound(cur);
			cur = tmp;
			
			id[z].erase(cur);
			ans[cur] = num;
			z = 1-z;
		}
		
		num++;
	}
	
	rep(i,0,2)
	for(int x:id[i]){
		ans[x] = num;
		num++;
	}
	
	cout<< num - 1 << "\n";
	rep(i,0,n) cout<<ans[i]<<" ";
	cout<<"\n";
	
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