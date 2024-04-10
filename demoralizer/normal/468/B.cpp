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

const int N=0;

int n,a,b;
set<int> s,stk,cur,sa,sb;

int dfsa(int x){
	if(stk.count(x)) return 1;
	cur.insert(x);
	if(!s.count(a-x))return 0;
	stk.insert(x);
	int ans=dfsa(a-x);
	if(s.count(b-x)) ans&=dfsa(b-x);
	stk.erase(x);
	return ans;
}

int p[100005];

void solve(){
	cin>>n>>a>>b;
	rep(i,0,n){
		int x;
		cin>>x;
		p[i]=x;
		s.insert(x);
	}
	
	for(int x:s){
		if(sa.count(x) || sb.count(x))continue;
		cur.clear();
		if(dfsa(x)){
			for(int y:cur){
				sa.insert(y);
			}
		}
		else{
			for(int y:cur){
				sb.insert(y);
			}
		}
	}
	
	for(int x:sb){
		if(!sb.count(b-x)){
			cout<<"NO";
			return;
		}
	}
	
	cout<<"YES\n";
	rep(i,0,n){
		cout<<sb.count(p[i])<<" ";
	}
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