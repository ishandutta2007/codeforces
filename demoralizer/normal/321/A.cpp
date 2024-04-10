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

const int N=0;

int sgn(int n){
	if(n<0)return -1;
	if(n==0)return 0;
	return 1;
}

void solve(){
	int a,b;
	string s;
	cin>>a>>b>>s;
	int x=0,y=0;
	for(char c:s){
		if(c=='U')y++;
		if(c=='D')y--;
		if(c=='R')x++;
		if(c=='L')x--;
	}
	
	for(char c:s){
		if((a==0 && b==0) || (a*y == b*x && sgn(a) == sgn(x) && sgn(b) == sgn(y) && ((x && a%x==0)||(y && b%y==0)))){
			cout<<"Yes";
			return;
		}
		if(c=='U')b--;
		if(c=='D')b++;
		if(c=='R')a--;
		if(c=='L')a++;
	}
	cout<<"No";
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