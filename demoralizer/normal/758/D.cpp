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


int n;
string k;

int getv(int i,int j){
	stringstream ss;
	rep(z,i,j+1){
		ss<<k[z];
	}
	int v;
	ss>>v;
	return v;
}

int check(int i,int j){
	if(i==j)return 1;
	if(k[i]=='0')return 0;
	int v=getv(i,j);
	return (n>v);
}

int pos[100];

void solve(){
	cin>>n>>k;
	
	rep(i,0,sz(k))pos[i]=i;
	
	rep(i,0,sz(k)){
		rep(j,i,sz(k)){
			if(check(i,j)){
				amin(pos[j],i);
			}
		}
	}
	int p=sz(k)-1,pw=1,ans=0;
	while(p>=0){
		ans+=pw*getv(pos[p],p);
		p=pos[p]-1;
		pw*=n;
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